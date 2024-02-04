#pragma once

#include <Eigen/Dense>
#include "Node.h"

class Cell {
public:
    Cell(int firstNodeIdx, int secondNodeIdx, int thirdNodeIdx,
         int firstFaceIdx, int secondFaceIdx, int thirdFaceIdx,
         int firstFaceAssocCellIdx, int secondFaceAssocCellIdx, int thirdFaceAssocCellIdx,
         std::vector<Node> const& nodes):
         _firstNodeIdx(firstNodeIdx), _secondNodeIdx(secondNodeIdx), _thirdNodeIdx(thirdNodeIdx),
         _firstFaceIdx(firstFaceIdx), _secondFaceIdx(secondFaceIdx), _thirdFaceIdx(thirdFaceIdx),
         _firstFaceAssocCellIdx(firstFaceAssocCellIdx), _secondFaceAssocCellIdx(secondFaceAssocCellIdx),
         _thirdFaceAssocCellIdx(thirdFaceAssocCellIdx) {
        Node const* node1 = &nodes[firstNodeIdx];
        Node const* node2 = &nodes[secondNodeIdx];
        Node const* node3 = &nodes[thirdNodeIdx];
        double x1 = node1->x();
        double y1 = node1->y();
        double x2 = node2->x();
        double y2 = node2->y();
        double x3 = node3->x();
        double y3 = node3->y();
        _centroid = {(x1+x2+x3)/3, (y1+y2+y3)/3};
    };
    Eigen::Vector2d centroid() const;
private:
    int _firstNodeIdx;
    int _secondNodeIdx;
    int _thirdNodeIdx;
    int _firstFaceIdx;
    int _secondFaceIdx;
    int _thirdFaceIdx;
    int _firstFaceAssocCellIdx;
    int _secondFaceAssocCellIdx;
    int _thirdFaceAssocCellIdx;
    Eigen::Vector2d _centroid;
};
