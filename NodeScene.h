#ifndef NODESCENE_H
#define NODESCENE_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include "NodeItem.h"

class NodeScene : public QGraphicsScene {
    Q_OBJECT

public:
    NodeScene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QGraphicsLineItem *tempLine;
    NodeItem *startNode;
};

#endif // NODESCENE_H
