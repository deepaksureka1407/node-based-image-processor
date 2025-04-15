#include "brightnesscontrastnode.h"

BrightnessContrastNode::BrightnessContrastNode(float alpha, int beta)
    : alpha(alpha), beta(beta) {}

void BrightnessContrastNode::setInput(const cv::Mat &input) {
    this->input = input;
}

void BrightnessContrastNode::process() {
    input.convertTo(output, -1, alpha, beta);
}

cv::Mat BrightnessContrastNode::getOutput() const {
    return output;
}