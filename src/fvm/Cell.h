#pragma once

class Cell {
public:
    Cell(int firstNodeIdx, int secondNodeIdx, int thirdNodeIdx,
         int firstFaceIdx, int secondFaceIdx, int thirdFaceIdx,
         int firstFaceAssocCellIdx, int secondFaceAssocCellIdx, int thirdFaceAssocCellIdx):
         _firstNodeIdx(firstNodeIdx), _secondNodeIdx(secondNodeIdx), _thirdNodeIdx(thirdNodeIdx),
         _firstFaceIdx(firstFaceIdx), _secondFaceIdx(secondFaceIdx), _thirdFaceIdx(thirdFaceIdx),
         _firstFaceAssocCellIdx(firstFaceAssocCellIdx), _secondFaceAssocCellIdx(secondFaceAssocCellIdx),
         _thirdFaceAssocCellIdx(thirdFaceAssocCellIdx)
         {};
private:
    int _firstNodeIdx;
    int _secondNodeIdx;
    int _thirdNodeIdx;
    int _firstFaceIdx;
    int _secondFaceIdx;
    int _thirdFaceIdx;
    int _firstFaceAssocCellIdx;
    int _secondFaceAssocCellIdx;
    int _thirdFaceAssocCellIdx;
};
