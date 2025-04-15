#include "colorchannelnode.h"

ColorChannelNode::ColorChannelNode(Channel ch) : channel(ch) {}

void ColorChannelNode::setInput(const cv::Mat &input) {
    this->input = input;
}

void ColorChannelNode::process() {
    std::vector<cv::Mat> channels;
    cv::split(input, channels);
    output = cv::Mat::zeros(input.size(), input.type());
    std::vector<cv::Mat> outCh(3, cv::Mat::zeros(input.size(), CV_8UC1));
    outCh[channel] = channels[channel];
    cv::merge(outCh, output);
}

cv::Mat ColorChannelNode::getOutput() const {
    return output;
}