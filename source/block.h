#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"



class Block
{
    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
        int rowOffset;
        int columnOffset;
    public:
        Block();
        void Draw(int offX, int offY);
        void Move(int rows, int columns);
        std::vector<Position> GetCellPositions();
        void Rotate();
        void UndoRotation();
        int id;
        std::map<int, std::vector<Position>> cells;
};