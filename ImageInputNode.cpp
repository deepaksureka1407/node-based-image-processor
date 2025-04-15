#include "ImageInputNode.h"
#include <opencv2/imgcodecs.hpp>
#include <QFileDialog>

ImageInputNode::ImageInputNode() : NodeItem("Image Input") {
    QPushButton *btn = new QPushButton("Load Image");
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
    proxy->setWidget(btn);
    proxy->setPos(10, 30);

    connect(btn, &QPushButton::clicked, [this]() {
        QString filePath = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Images (*.png *.jpg *.bmp)");
        if (!filePath.isEmpty()) {
            loadImage(filePath);
        }
    });
}

void ImageInputNode::loadImage(const QString &filePath) {
    imagePath = filePath;
    inputImage = cv::imread(filePath.toStdString());
    process();
}

void ImageInputNode::process() {
    outputImage = inputImage.clone(); // no processing, just load
}
