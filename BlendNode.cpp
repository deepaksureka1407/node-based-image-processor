#include "blendnode.h"

BlendNode::BlendNode(double alpha) : alpha(alpha) {}

void BlendNode::setInputs(const cv::Mat &a, const cv::Mat &b) {
    img1 = a;
    img2 = b;
}

void BlendNode::process() {
    cv::addWeighted(img1, alpha, img2, 1 - alpha, 0.0, output);
}

cv::Mat BlendNode::getOutput() const {
    return output;
}
