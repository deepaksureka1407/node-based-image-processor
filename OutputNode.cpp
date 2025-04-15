#include "OutputNode.h"
#include <QImage>
#include <QLabel>
#include <QPixmap>

OutputNode::OutputNode() : NodeItem("Output") {}

void OutputNode::process() {
    if (inputImage.empty()) return;

    cv::Mat rgb;
    cv::cvtColor(inputImage, rgb, cv::COLOR_BGR2RGB);

    QImage qimg(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);
    QLabel *preview = new QLabel;
    preview->setPixmap(QPixmap::fromImage(qimg));
    preview->setWindowTitle("Final Output");
    preview->resize(qimg.size());
    preview->show();

    outputImage = inputImage.clone(); // pass-through
}
