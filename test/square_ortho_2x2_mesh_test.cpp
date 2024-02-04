#include <gtest/gtest.h>
#include <Eigen/Dense>
#include "fvm/Mesh.h"

class SquareOrtho2x2MeshTest : public testing::Test {
protected:
    Mesh mesh{"square_ortho_2x2"};
};

TEST_F(SquareOrtho2x2MeshTest, FaceVectorCalculation) {
    // In the square orthogonal 2x2 mesh, all face vectors are either in the direction of: (0, 1), (1, 0), or (1, 1)
    double eps = 1e-6;
    for (auto& face: mesh.faces()) {
        if (abs(face.vector().dot(Eigen::Vector2d{0, 1})) < eps) {
            continue;
        } else if (abs(face.vector().dot(Eigen::Vector2d{1, 0})) < eps) {
            continue;
        } else if (abs(face.vector().dot(Eigen::Vector2d{1, 1})) < eps) {
            continue;
        } else {
            FAIL();
        }
    }
}