#pragma once

#include <string>
#include <vector>
#include "Node.h"
#include "Face.h"
#include "Cell.h"

class Mesh {
public:
    explicit Mesh(char const* meshName);
private:
    size_t _nNodes{};
    size_t _nFaces{};
    size_t _nCells{};
    std::vector<Node> _nodes;
    std::vector<Face> _faces;
    std::vector<Cell> _cells;
};