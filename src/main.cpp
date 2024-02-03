#include <iostream>
#include "fvm/Mesh.h"

int main() {
    try {
        Mesh mesh("square_ortho_2x2");
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
