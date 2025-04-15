#ifndef THRESHOLDNODE_H
#define THRESHOLDNODE_H

#include "node.h"

class ThresholdNode : public Node {
public:
    ThresholdNode(double thresh = 127, double maxVal = 255);
    void setInput(const cv::Mat &input);
    void process() override;
    cv::Mat getOutput() const override;

private:
    double thresh, maxVal;
    cv::Mat input, output;
};

#endif // THRESHOLDNODE_H