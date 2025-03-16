
#include "grid.h"
#include <iostream>
#include "colors.h"


Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    colors = GetCellColors();
    Init();
}

void Grid::Init()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    
    if(row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int r = numRows - 1; r >=0; r--)
    {
        if(IsRowFull(r))
        {
            ClearRow(r);
            completed++;
        } 
        else if(completed > 0)
        {
            MoveRowDown(r, completed);
        }

    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for(int c = 0; c < numCols; c++)
    {
        if(grid[row][c] == 0)
        {
            return false;
        }
    }
    return true;

}

void Grid::ClearRow(int row)
{
    for(int c = 0; c < numCols; c++)
    {
        grid[row][c] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int c = 0; c < numCols; c++)
    {
        grid[row + numRows][c] = grid[row][c];
        grid[row][c] = 0;
    }
}
