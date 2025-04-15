#ifndef COLORCHANNELNODE_H
#define COLORCHANNELNODE_H

#include "node.h"

class ColorChannelNode : public Node {
public:
    enum Channel { RED, GREEN, BLUE };
    ColorChannelNode(Channel ch);
    void setInput(const cv::Mat &input);
    void process() override;
    cv::Mat getOutput() const override;

private:
    Channel channel;
    cv::Mat input, output;
};

#endif // COLORCHANNELNODE_H