#ifndef CONVOLUTIONFILTERNODE_H
#define CONVOLUTIONFILTERNODE_H

#include "node.h"

class ConvolutionFilterNode : public Node {
public:
    ConvolutionFilterNode(const cv::Mat &kernel);
    void setInput(const cv::Mat &input);
    void process() override;
    cv::Mat getOutput() const override;

private:
    cv::Mat input, output, kernel;
};

#endif // CONVOLUTIONFILTERNODE_H