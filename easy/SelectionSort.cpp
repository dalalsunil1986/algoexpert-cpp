#include <vector>

std::vector<int> selectionSort(std::vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        int minElementIndex = i;
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[minElementIndex])
            {
                minElementIndex = j;
            }
        }

        if (minElementIndex != i)
        {
            std::swap(array[i], array[minElementIndex]);
        }
    }

    return array;
}
