#include <iostream>
#include "fvm/Mesh.h"
#include "fvm/Discretization.h"
#include "io/write_vtk.h"

int main() {
    try {
        Mesh mesh("square_ortho_20x20");
        Discretization discretization(mesh, 1, 0.01);
        Eigen::VectorXd phi = discretization.A().colPivHouseholderQr().solve(discretization.b());
        std::cout << phi << std::endl;
        writeVTK("out.vtk", "data", mesh, phi, "scalar");
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
