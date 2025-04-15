#ifndef CONNECTIONITEM_H
#define CONNECTIONITEM_H

#include <QGraphicsLineItem>

class NodeItem;

class ConnectionItem : public QGraphicsLineItem {
public:
    ConnectionItem(NodeItem* fromNode, NodeItem* toNode, QGraphicsItem* parent = nullptr);

    NodeItem* from;
    NodeItem* to;
};

#endif // CONNECTIONITEM_H
