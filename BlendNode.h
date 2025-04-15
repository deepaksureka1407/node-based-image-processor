#ifndef BLENDNODE_H
#define BLENDNODE_H

#include "node.h"

class BlendNode : public Node {
public:
    BlendNode(double alpha = 0.5);
    void setInputs(const cv::Mat &a, const cv::Mat &b);
    void process() override;
    cv::Mat getOutput() const override;

private:
    double alpha;
    cv::Mat img1, img2, output;
};

#endif // BLENDNODE_H