#include "nodeeditor.h"

NodeEditor::NodeEditor(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 1600, 1200);
}