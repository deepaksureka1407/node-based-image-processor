#ifndef NODEEDITOR_H
#define NODEEDITOR_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "node.h"

class NodeEditor : public QGraphicsView {
    Q_OBJECT

public:
    NodeEditor(QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;
};

#endif // NODEEDITOR_H