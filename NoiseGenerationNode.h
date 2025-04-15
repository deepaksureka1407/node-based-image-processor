#ifndef NOISEGENNODE_H
#define NOISEGENNODE_H

#include "node.h"

class NoiseGenNode : public Node {
public:
    NoiseGenNode(int width, int height);
    void process() override;
    cv::Mat getOutput() const override;

private:
    int width, height;
    cv::Mat output;
};

#endif // NOISEGENNODE_H