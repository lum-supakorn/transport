#pragma once

#include <Eigen/Dense>
#include "Mesh.h"

class Discretization {
public:
    explicit Discretization(Mesh const& mesh, double rho, double Gamma);
    void printLinearSystem();
    [[nodiscard]] Eigen::MatrixXd const& A() const;
    [[nodiscard]] Eigen::VectorXd const& b() const;
private:
    size_t nCells;
    Eigen::MatrixXd A_;
    Eigen::VectorXd b_;
};