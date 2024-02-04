#pragma once

#include <iostream>

class Node {
public:
    Node(double x, double y, double z): _x(x), _y(y), _z(z) {};
    friend std::ostream& operator<<(std::ostream& output, Node& node);
    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
private:
    double _x;
    double _y;
    double _z;
};