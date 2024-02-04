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

TEST_F(SquareOrtho2x2MeshTest, BoundaryFaceNeighborCell) {
    // Boundary faces should not have neighbor cell (neighbor cell index must be -1)
    for (auto& face: mesh.faces()) {
        if (face.isBoundary()) {
            if (face.neighborCellIdx() != -1) {
                FAIL();
            }
        }
    }
}

TEST_F(SquareOrtho2x2MeshTest, FaceVectorOrientation) {
    // The vector of all faces should point away from its owner cell centroid and into its neighbor cell centroid
    for (auto const& face: mesh.faces()) {
        Cell const* ownerCell = &mesh.cells()[face.ownerCellIdx()];
        Cell const* neighborCell = &mesh.cells()[face.neighborCellIdx()];
        Eigen::Vector2d ownerCentroidToFaceMid = face.mid() - ownerCell->centroid();
        Eigen::Vector2d neighborCentroidToFaceMid = face.mid() - neighborCell->centroid();
        if (ownerCentroidToFaceMid.dot(face.vector()) < 0) {
            FAIL();
        }
        // For internal faces, check whether the face vector points into the neighbor cell as well
        if (!face.isBoundary()) {
            if (neighborCentroidToFaceMid.dot(face.vector()) > 0) {
                FAIL();
            }
        }
    }
}