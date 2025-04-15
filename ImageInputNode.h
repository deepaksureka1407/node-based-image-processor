#ifndef IMAGEINPUTNODE_H
#define IMAGEINPUTNODE_H

#include "NodeItem.h"
#include <QString>

class ImageInputNode : public NodeItem {
public:
    ImageInputNode();

    void loadImage(const QString &filePath);
    void process() override;

private:
    QString imagePath;
};

#endif // IMAGEINPUTNODE_H
