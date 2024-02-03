#pragma once

class Face {
public:
    Face(int firstNodeIdx, int secondNodeIdx, int physGroupIdx, int ownerCellIdx, int neighborCellIdx):
        _firstNodeIdx(firstNodeIdx), _secondNodeIdx(secondNodeIdx),
        _physGroupIdx(physGroupIdx), _ownerCellIdx(ownerCellIdx), _neighborCellIdx(neighborCellIdx) {};
private:
    int _firstNodeIdx;
    int _secondNodeIdx;
    int _physGroupIdx;
    int _ownerCellIdx;
    int _neighborCellIdx;
};
