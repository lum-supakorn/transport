#pragma once

#include <Eigen/Dense>
#include "Mesh.h"

class Discretization {
public:
    explicit Discretization(Mesh const& mesh, double rho, double Gamma);
private:
    size_t nCells;
    Eigen::MatrixXd A;
    Eigen::VectorXd b;
};