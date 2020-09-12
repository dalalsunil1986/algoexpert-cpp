#include <vector>

std::vector<int> spiralTraverse(std::vector<std::vector<int>> array)
{
    if (array.empty())
    {
        return {};
    }

    int x = 0;
    int y = 0;
    int lowerBorderX = 0;
    int lowerBorderY = 0;
    int originX = 0;
    int originY = 0;
    int upperBorderY = array.size() - 1;
    int upperBorderX = array[0].size() - 1;
    std::vector<int> spiral;

    while (spiral.size() != (array.size()) * (array[0].size()))
    {
        spiral.push_back(array[y][x]);
        if (x != upperBorderX && y == lowerBorderY)
        {
            x++;
        }
        else if (x == upperBorderX && y != upperBorderY)
        {
            y++;
        }
        else if (x != lowerBorderX && y == upperBorderY)
        {
            x--;
        }
        else if (x == lowerBorderX && y != lowerBorderY)
        {
            y--;
        }

        if (x == originX && y == originY)
        {
            x = ++originX;
            y = ++originY;
            lowerBorderX++;
            lowerBorderY++;
            upperBorderX--;
            upperBorderY--;
        }
    }

    return spiral;
}