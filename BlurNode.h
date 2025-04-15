#ifndef BLURNODE_H
#define BLURNODE_H

#include "NodeItem.h"

class BlurNode : public NodeItem {
public:
    BlurNode();

    void process() override;

private:
    int blurRadius = 5;
};

#endif // BLURNODE_H
