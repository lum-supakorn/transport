#pragma once

#include <string>
#include <fstream>
#include <fvm/Mesh.h>

void writeVTK(std::string const& filePath, std::string const& header,
              Mesh const& mesh, std::vector<double> const& data, std::string const& dataName) {
    std::ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Error opening file for writing!");
    }

    outputFile << "# vtk DataFile Version 2.0\n";
    outputFile << header << std::endl;
    outputFile << "ASCII\n";
    outputFile << "DATASET UNSTRUCTURED_GRID\n";

    // Points
    outputFile << "POINTS " << mesh.nNodes() << " float\n";
    for (auto& node: mesh.nodes()) {
        outputFile << node.x() << " " << node.y() << " 0.0\n";
    }

    // Cells
    short nodePerCell = 3;
    outputFile << "CELLS " << mesh.nCells() << " " << (1+nodePerCell)*mesh.nCells() << std::endl;
    for (auto& cell: mesh.cells()) {
        outputFile << nodePerCell;
        for (auto& nodeIdx: cell.nodeIdx()) {
            outputFile << " " << nodeIdx;
        }
        outputFile << std::endl;
    }

    outputFile << "CELL_TYPES " << mesh.nCells() << std::endl;
    for (int i = 0; i < mesh.nCells(); i++) {
        outputFile << "5\n";
    }

    // Data
    outputFile << "CELL_DATA " << mesh.nCells() << std::endl;
    outputFile << "SCALARS " << dataName << " float\n";
    outputFile << "LOOKUP_TABLE default\n";
    for (auto& item: data) {
        outputFile << item << std::endl;
    }

    outputFile.close();
}