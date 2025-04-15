#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <opencv2/opencv.hpp>

class Node : public QGraphicsItem {
public:
    virtual void process() = 0;
    virtual cv::Mat getOutput() const = 0;
};

#endif // NODE_H