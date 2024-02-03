#include "Node.h"

std::ostream& operator<<(std::ostream &output, Node &node) {
    output << "(" << node._x << ", " << node._y << ", " << node._z << ")" << std::endl;
    return output;
}
