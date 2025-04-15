#ifndef EDGEDETECTIONNODE_H
#define EDGEDETECTIONNODE_H

#include "node.h"

class EdgeDetectionNode : public Node {
public:
    EdgeDetectionNode();
    void setInput(const cv::Mat &input);
    void process() override;
    cv::Mat getOutput() const override;

private:
    cv::Mat input, output;
};

#endif // EDGEDETECTIONNODE_H