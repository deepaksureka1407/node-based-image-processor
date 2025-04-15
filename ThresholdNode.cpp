#include "thresholdnode.h"

ThresholdNode::ThresholdNode(double thresh, double maxVal) : thresh(thresh), maxVal(maxVal) {}

void ThresholdNode::setInput(const cv::Mat &input) {
    this->input = input;
}

void ThresholdNode::process() {
    cv::cvtColor(input, input, cv::COLOR_BGR2GRAY);
    cv::threshold(input, output, thresh, maxVal, cv::THRESH_BINARY);
}

cv::Mat ThresholdNode::getOutput() const {
    return output;
}