#include "ConnectionItem.h"
#include "NodeItem.h"

ConnectionItem::ConnectionItem(NodeItem* fromNode, NodeItem* toNode, QGraphicsItem* parent)
    : QGraphicsLineItem(QLineF(fromNode->outputPort(), toNode->inputPort()), parent),
      from(fromNode), to(toNode) {
    setPen(QPen(Qt::black, 2));
}
