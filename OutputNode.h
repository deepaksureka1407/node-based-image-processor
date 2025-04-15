#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

#include "NodeItem.h"

class OutputNode : public NodeItem {
public:
    OutputNode();

    void process() override;
};

#endif // OUTPUTNODE_H
