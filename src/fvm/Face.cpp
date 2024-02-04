#include "Face.h"

Eigen::Vector2d Face::vector() const {
    return _vector;
}

Eigen::Vector2d Face::mid() const {
    return _mid;
}

int Face::ownerCellIdx() const {
    return _ownerCellIdx;
}

int Face::neighborCellIdx() const {
    return _neighborCellIdx;
}

bool Face::isBoundary() const {
    return (_physGroupIdx != -1);
}

std::ostream& operator<<(std::ostream &output, Face& face) {
    output << "node: " << face._firstNodeIdx << ", " << face._secondNodeIdx <<
    " phys_group: " << face._physGroupIdx <<
    " owner: " << face._ownerCellIdx << " neighbor: " << face._neighborCellIdx << std::endl;
    return output;
}
