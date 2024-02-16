#pragma once

#include <string>
#include <vector>
#include "Node.h"
#include "Face.h"
#include "Cell.h"

class Mesh {
public:
    explicit Mesh(char const* meshName);
    [[nodiscard]] size_t nNodes() const;
    [[nodiscard]] size_t nCells() const;
    [[nodiscard]] std::vector<Node> const& nodes() const;
    [[nodiscard]] std::vector<Face> const& faces() const;
    [[nodiscard]] std::vector<Cell> const& cells() const;
private:
    size_t _nNodes{};
    size_t _nFaces{};
    size_t _nCells{};
    std::vector<Node> _nodes;
    std::vector<Face> _faces;
    std::vector<Cell> _cells;
};
