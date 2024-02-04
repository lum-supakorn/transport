#pragma once

#include <Eigen/Dense>
#include "Node.h"
#include "Cell.h"

class Face {
public:
    Face(int firstNodeIdx, int secondNodeIdx, int physGroupIdx, int ownerCellIdx, int neighborCellIdx,
         std::vector<Node> const& nodes, std::vector<Cell> const& cells):
        _firstNodeIdx(firstNodeIdx), _secondNodeIdx(secondNodeIdx),
        _physGroupIdx(physGroupIdx), _ownerCellIdx(ownerCellIdx), _neighborCellIdx(neighborCellIdx) {
        Node const* node1 = &nodes[firstNodeIdx];
        Node const* node2 = &nodes[secondNodeIdx];
        Eigen::Vector2d r1{node1->x(), node1->y()}; // Displacement vector of the first node
        Eigen::Vector2d r2{node2->x(), node2->y()}; // Displacement vector of the second node
        _length = (r2-r1).norm();
        Eigen::Vector2d dr = r2-r1; // Line segment vector of the face (node 1 points to node 2)
        _vector = {-dr(1), dr(0)};
        // Now we have to check whether the above face vector points away from the owner cell's centroid.
        // If this is not the case, we need to flip it.
        Cell const* ownerCell = &cells[ownerCellIdx];
        if (ownerCell->centroid().dot(_vector) < 0) {
            _vector *= -1;
        }
        _normal = _vector.normalized();
    };
    [[nodiscard]] Eigen::Vector2d vector() const;
private:
    int _firstNodeIdx;
    int _secondNodeIdx;
    int _physGroupIdx;
    int _ownerCellIdx;
    int _neighborCellIdx;
    double _length;
    Eigen::Vector2d _vector;
    Eigen::Vector2d _normal;
};
