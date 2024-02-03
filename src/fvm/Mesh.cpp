#include "Mesh.h"

#include <fstream>
#include <iostream>

Mesh::Mesh(char const* meshName) {
    std::string meshNameStr{meshName};
    // Node
    std::cout << "Reading nodes..." << std::endl;
    std::ifstream meshNodeFile("../mesh/" + meshNameStr + "/node");
    if (!meshNodeFile.is_open()) {
        throw std::runtime_error("Error reading mesh node data.");
    }
    meshNodeFile >> _nNodes;
    if (_nNodes <= 0) {
        throw std::runtime_error("Invalid number of nodes.");
    }
    for (size_t i = 0; i < _nNodes; i++) {
        double x, y, z;
        meshNodeFile >> x >> y >> z;
        _nodes.emplace_back(x, y, z);
    }
    meshNodeFile.close();
    // Face
    std::cout << "Reading faces..." << std::endl;
    std::ifstream meshFaceFile("../mesh/" + meshNameStr + "/face");
    if (!meshFaceFile.is_open()) {
        throw std::runtime_error("Error reading mesh face data.");
    }
    meshFaceFile >> _nFaces;
    if (_nFaces <= 0) {
        throw std::runtime_error("Invalid number of faces.");
    }
    for (size_t i = 0; i < _nFaces; i++) {
        int firstNodeIdx, secondNodeIdx, physGroupIdx, ownerCellIdx, neighborCellIdx;
        meshFaceFile >> firstNodeIdx >> secondNodeIdx >> physGroupIdx >> ownerCellIdx >> neighborCellIdx;
        _faces.emplace_back(firstNodeIdx, secondNodeIdx, physGroupIdx, ownerCellIdx, neighborCellIdx);
    }
    meshFaceFile.close();
    // Cell
    std::cout << "Reading cells..." << std::endl;
    std::ifstream meshCellFile("../mesh/" + meshNameStr + "/cell");
    if (!meshCellFile.is_open()) {
        throw std::runtime_error("Error reading mesh cell data.");
    }
    meshCellFile >> _nCells;
    if (_nCells <= 0) {
        throw std::runtime_error("Invalid number of cells.");
    }
    for (size_t i = 0; i < _nCells; i++) {
        int firstNodeIdx, secondNodeIdx, thirdNodeIdx;
        int firstFaceIdx, secondFaceIdx, thirdFaceIdx;
        int firstFaceAssocCellIdx, secondFaceAssocCellIdx, thirdFaceAssocCellIdx;
        meshCellFile >> firstNodeIdx >> secondNodeIdx >> thirdNodeIdx >> firstFaceIdx >> secondFaceIdx >> thirdFaceIdx
        >> firstFaceAssocCellIdx >> secondFaceAssocCellIdx >> thirdFaceAssocCellIdx;
        _cells.emplace_back(firstNodeIdx, secondNodeIdx, thirdNodeIdx, firstFaceIdx, secondFaceIdx, thirdFaceIdx,
                            firstFaceAssocCellIdx, secondFaceAssocCellIdx, thirdFaceAssocCellIdx);
    }
    meshCellFile.close();
    std::cout << "Got " << _nNodes << " nodes, " << _nFaces << " faces, and " << _nCells << " cells." << std::endl;
}