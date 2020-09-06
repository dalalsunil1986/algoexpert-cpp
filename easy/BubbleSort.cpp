#include <vector>

std::vector<int> bubbleSort(std::vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 1; j < array.size(); j++)
        {
            if (array[j] < array[j - 1])
            {
                std::swap(array[j], array[j - 1]);
            }
        }
    }
    return array;
}
