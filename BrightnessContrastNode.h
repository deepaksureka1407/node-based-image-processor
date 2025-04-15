#ifndef BRIGHTNESSCONTRASTNODE_H
#define BRIGHTNESSCONTRASTNODE_H

#include "nodes/node.h"

class BrightnessContrastNode : public Node {
public:
    BrightnessContrastNode(float alpha = 1.0f, int beta = 0);
    void setInput(const cv::Mat &input);
    void process() override;
    cv::Mat getOutput() const override;

private:
    float alpha; // contrast
    int beta;    // brightness
    cv::Mat input, output;
};

#endif // BRIGHTNESSCONTRASTNODE_H