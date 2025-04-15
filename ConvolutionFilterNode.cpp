#include "convolutionfilternode.h"

ConvolutionFilterNode::ConvolutionFilterNode(const cv::Mat &kernel) : kernel(kernel) {}

void ConvolutionFilterNode::setInput(const cv::Mat &input) {
    this->input = input;
}

void ConvolutionFilterNode::process() {
    cv::filter2D(input, output, -1, kernel);
}

cv::Mat ConvolutionFilterNode::getOutput() const {
    return output;
}