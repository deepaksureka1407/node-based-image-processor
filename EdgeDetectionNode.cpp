#include "edgedetectionnode.h"

EdgeDetectionNode::EdgeDetectionNode() {}

void EdgeDetectionNode::setInput(const cv::Mat &input) {
    this->input = input;
}

void EdgeDetectionNode::process() {
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, output, 50, 150);
}

cv::Mat EdgeDetectionNode::getOutput() const {
    return output;
}
