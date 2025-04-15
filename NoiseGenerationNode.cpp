#include "noisegennode.h"

NoiseGenNode::NoiseGenNode(int width, int height) : width(width), height(height) {}

void NoiseGenNode::process() {
    output = cv::Mat(height, width, CV_8UC1);
    cv::randu(output, 0, 255);
}

cv::Mat NoiseGenNode::getOutput() const {
    return output;
}
