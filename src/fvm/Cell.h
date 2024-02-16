#pragma once

#include <Eigen/Dense>
#include "Node.h"

class Cell {
public:
    Cell(int firstNodeIdx, int secondNodeIdx, int thirdNodeIdx,
         int firstFaceIdx, int secondFaceIdx, int thirdFaceIdx,
         int firstFaceAssocCellIdx, int secondFaceAssocCellIdx, int thirdFaceAssocCellIdx,
         std::vector<Node> const& nodes):
         _nodeIdx{std::vector<int>{firstNodeIdx, secondNodeIdx, thirdNodeIdx}},
         _faceIdx{std::vector<int>{firstFaceIdx, secondFaceIdx, thirdFaceIdx}},
         _faceAssocCellIdx{std::vector<int>{firstFaceAssocCellIdx, secondFaceAssocCellIdx, thirdFaceAssocCellIdx}} {
        Node const* node1 = &nodes[firstNodeIdx];
        Node const* node2 = &nodes[secondNodeIdx];
        Node const* node3 = &nodes[thirdNodeIdx];
        _centroid = {(node1->x()+node2->x()+node3->x())/3, (node1->y()+node2->y()+node3->y())/3};
    };
    [[nodiscard]] Eigen::Vector2d centroid() const;
    [[nodiscard]] std::vector<int> faceIdx() const;
    [[nodiscard]] std::vector<int> faceAssocCellIdx() const;
private:
    std::vector<int> _nodeIdx;
    std::vector<int> _faceIdx;
    std::vector<int> _faceAssocCellIdx;
    Eigen::Vector2d _centroid;
};
