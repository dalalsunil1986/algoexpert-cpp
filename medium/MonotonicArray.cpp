#include <vector>

bool isMonotonic(std::vector<int> array)
{
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (int i = 1; i < array.size(); i++)
    {
        if (array[i - 1] < array[i])
        {
            isDecreasing = false;
        }
        else if (array[i - 1] > array[i])
        {
            isIncreasing = false;
        }
    }
    return isIncreasing || isDecreasing;
}
