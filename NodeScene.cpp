#include "nodes\NodeScene.h"
#include <QGraphicsSceneMouseEvent>
#include <QPen>

NodeScene::NodeScene(QObject *parent) : QGraphicsScene(parent), tempLine(nullptr), startNode(nullptr) {}

void NodeScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    auto item = itemAt(event->scenePos(), QTransform());
    for (QGraphicsItem *item : items(event->scenePos())) {
        auto *node = dynamic_cast<NodeItem*>(item);
        if (node && node->isOnOutputPort(event->scenePos())) {
            startNode = node;
            break;
        }
    }
    

    if (startNode) {
        QPointF port = startNode->outputPort();
        tempLine = addLine(QLineF(port, event->scenePos()), QPen(Qt::red, 2));
    } else {
        QGraphicsScene::mousePressEvent(event);
    }
}

void NodeScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (tempLine) {
        QLineF newLine(tempLine->line().p1(), event->scenePos());
        tempLine->setLine(newLine);
    } else {
        QGraphicsScene::mouseMoveEvent(event);
    }
}

void NodeScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (tempLine) {
        auto item = itemAt(event->scenePos(), QTransform());
        NodeItem *endNode = dynamic_cast<NodeItem*>(item);

        if (endNode && endNode != startNode) {
            addLine(QLineF(startNode->outputPort(), endNode->inputPort()), QPen(Qt::black, 2));
        }

        removeItem(tempLine);
        delete tempLine;
        tempLine = nullptr;
    } else {
        QGraphicsScene::mouseReleaseEvent(event);
    }
}

void executeGraph(NodeItem* startNode) {
    std::set<NodeItem*> visited;

    std::function<void(NodeItem*)> dfs = [&](NodeItem* node) {
        if (!node || visited.count(node)) return;
        visited.insert(node);

        // Process all inputs first
        for (NodeItem* inputNode : node->inputs) {
            dfs(inputNode);
        }

        // Process this node
        if (!node->inputs.empty()) {
            node->setInputImage(node->inputs[0]->getOutputImage());  // assumes 1 input for now
        }
        node->process();
    };

    dfs(startNode);
}
