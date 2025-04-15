#include "NodeItem.h"

NodeItem::NodeItem(QString title, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_title(title) {
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF NodeItem::boundingRect() const {
    return QRectF(0, 0, 160, 100);
}

void NodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    // Node background
    painter->setBrush(isSelected() ? QColor("#aaffaa") : QColor("#cccccc"));
    painter->drawRoundedRect(boundingRect(), 10, 10);

    // Title
    painter->setPen(Qt::black);
    painter->drawText(10, 20, m_title);

    // Example input/output pins (draw circles)
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPointF(0, 50), 5, 5);   // input
    painter->drawEllipse(QPointF(160, 50), 5, 5); // output

    // Draw labels for ports
    painter->drawText(QPointF(5, 70), inputLabel);
    painter->drawText(QPointF(130, 70), outputLabel);
    
    QColor color = isSelected() ? QColor("#ffddaa") : QColor("#eeeeee");
    painter->setBrush(color);
    painter->drawRoundedRect(boundingRect(), 10, 10);

}

void NodeItem::setTitle(const QString &newTitle) {
    m_title = newTitle;
    update();
}

QString NodeItem::title() const {
    return m_title;
}

QPointF NodeItem::inputPort() const {
    return mapToScene(QPointF(0, 50)); // Left side
}

QPointF NodeItem::outputPort() const {
    return mapToScene(QPointF(160, 50)); // Right side
}

void NodeItem::addSlider(const QString &labelText, int min, int max, int initialValue) {
    QWidget *container = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->setContentsMargins(5, 25, 5, 5);
    layout->setSpacing(2);

    QLabel *label = new QLabel(labelText);
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(min, max);
    slider->setValue(initialValue);

    layout->addWidget(label);
    layout->addWidget(slider);

    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
    proxy->setWidget(container);
    proxy->setPos(10, 30);  // inside the node
}

QRectF NodeItem::inputPortRect() const {
    QPointF center = QPointF(0, 50);
    return mapToScene(QRectF(center.x() - 6, center.y() - 6, 12, 12)).boundingRect();
}

QRectF NodeItem::outputPortRect() const {
    QPointF center = QPointF(160, 50);
    return mapToScene(QRectF(center.x() - 6, center.y() - 6, 12, 12)).boundingRect();
}

bool NodeItem::isOnInputPort(QPointF scenePos) const {
    return inputPortRect().contains(scenePos);
}

bool NodeItem::isOnOutputPort(QPointF scenePos) const {
    return outputPortRect().contains(scenePos);
}

void NodeItem::setInputImage(const cv::Mat &image) {
    inputImage = image.clone();
    process();  // Automatically reprocess
}

cv::Mat NodeItem::getOutputImage() const {
    return outputImage;
}

void NodeItem::process() {
    // Default: just copy input to output
    outputImage = inputImage.clone();
}

void NodeItem::addOutput(NodeItem* other) {
    outputs.push_back(other);
}

void NodeItem::addInput(NodeItem* other) {
    inputs.push_back(other);
}
