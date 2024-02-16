#include "Cell.h"

Eigen::Vector2d Cell::centroid() const {
    return _centroid;
}

std::vector<int> Cell::faceIdx() const {
    return _faceIdx;
}

std::vector<int> Cell::faceAssocCellIdx() const {
    return _faceAssocCellIdx;
}
