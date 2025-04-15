#include "BlurNode.h"
#include <opencv2/imgproc.hpp>

BlurNode::BlurNode() : NodeItem("Blur") {
    addSlider("Radius", 1, 15, blurRadius);
}

void BlurNode::process() {
    if (!inputImage.empty()) {
        int radius = blurRadius;
        if (radius % 2 == 0) radius += 1; // GaussianBlur needs odd kernel size
        cv::GaussianBlur(inputImage, outputImage, cv::Size(radius, radius), 0);
    }
}
