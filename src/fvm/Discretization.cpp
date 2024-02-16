#include "Discretization.h"

Discretization::Discretization(Mesh const& mesh, double rho, double Gamma) {
    nCells = mesh.cells().size();
    A_ = Eigen::MatrixXd::Zero(static_cast<long>(nCells), static_cast<long>(nCells));
    b_ = Eigen::VectorXd::Zero(static_cast<long>(nCells));
    // Loop over cells
    for (int i = 0; i < nCells; i++) {
        Cell const* cell = &mesh.cells()[i];
        // Loop over faces
        for (short k = 0; k < 3; k++) {
            Face const* face = &mesh.faces()[cell->faceIdx()[k]];
            Eigen::Vector2d r_k = face->mid();
            Eigen::Vector2d r_P = cell->centroid();
            Eigen::Vector2d v_k = {face->mid().x(), -face->mid().y()};
            if (!face->isBoundary()) {
                int j = cell->faceAssocCellIdx()[k];
                Cell const* neighborCell = &mesh.cells()[j];
                // Geometrical variables for convection
                Eigen::Vector2d S_k = face->vector();
                if (i != face->ownerCellIdx()) S_k *= -1;
                double v_dot_S = v_k.dot(S_k);
                Eigen::Vector2d r_Nk = neighborCell->centroid();
                double xi_k = (r_k-r_P).dot(r_Nk-r_P)/(r_Nk-r_P).squaredNorm();
                // Convection contribution
                A_(i,i) += rho*(1-xi_k)*v_dot_S;
                A_(i,j) += rho*xi_k*v_dot_S;
                // Geometrical variables for diffusion
                Eigen::Vector2d n = S_k.normalized();
                double beta = std::min((r_k-r_P).dot(n), (r_Nk-r_k).dot(n));
                Eigen::Vector2d r_P_prime = r_k - beta*n;
                Eigen::Vector2d r_Nk_prime = r_k + beta*n;
                // Diffusion contribution
                double a_d_P = Gamma*S_k.norm()/(r_Nk_prime - r_P_prime).norm();
                A_(i,i) += a_d_P;
                A_(i,j) += -a_d_P;
                continue;
            } else {
                Eigen::Vector2d S_k = face->vector();
                double v_dot_S = v_k.dot(S_k);
                switch (face->physGroupIdx()) {
                    case 0:     // Top
                    case 3: {   // Left
                        double phi_k = face->physGroupIdx() == 0 ? 0 : 1;
                        // Convection contribution
                        b_(i) += -rho * phi_k * v_dot_S;
                        // Diffusion contribution
                        Eigen::Vector2d n = S_k.normalized();
                        Eigen::Vector2d r_P_prime = r_k - ((r_k - r_P).dot(n)) * n;
                        double coeff = Gamma * S_k.norm() / (r_k - r_P_prime).norm();
                        A_(i, i) += coeff;
                        b_(i) += coeff * phi_k;
                        break;
                    }
                    case 1:     // Right
                    case 2: {   // Bottom
                        A_(i, i) += rho * v_dot_S;
                    }
                }
            }
        }
    }
}

void Discretization::printLinearSystem() {
    std::cout << "A:" << std::endl;
    std::cout << A_ << std::endl;
    std::cout << "b:" << std::endl;
    std::cout << b_ << std::endl;
}

Eigen::MatrixXd const& Discretization::A() const {
    return A_;
}

Eigen::VectorXd const& Discretization::b() const {
    return b_;
}
