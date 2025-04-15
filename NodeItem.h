#ifndef NODEITEM_H
#define NODEITEM_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <opencv2/opencv.hpp>

class NodeItem : public QGraphicsItem
{
public:
    void setInputImage(const cv::Mat &image);
    cv::Mat getOutputImage() const;
    virtual void process(); // Overridden by custom nodes
    NodeItem(QString title = "Node", QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setTitle(const QString &newTitle);
    QString title() const;
    QPointF inputPort() const;
    QPointF outputPort() const;
    QRectF inputPortRect() const;
    QRectF outputPortRect() const;
    bool isOnInputPort(QPointF scenePos) const;
    bool isOnOutputPort(QPointF scenePos) const;

    QString inputLabel = "In";
    QString outputLabel = "Out";
    void addSlider(const QString &labelText, int min, int max, int initialValue);
    std::vector<NodeItem*> outputs;  // Who receives my output?
    std::vector<NodeItem*> inputs;   // Who gives me input?

    void addOutput(NodeItem* other);
    void addInput(NodeItem* other);
protected:
    cv::Mat inputImage;
    cv::Mat outputImage;
    QPointF dragStartPos;
    QString m_title;
};

#endif // NODEITEM_H
