#include <vector>

std::vector<int> insertionSort(std::vector<int> array)
{
    int sortedSubArrayEndIndex = 0;

    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] < array[sortedSubArrayEndIndex])
        {
            std::swap(array[i], array[sortedSubArrayEndIndex]);

            for (int j = sortedSubArrayEndIndex; j > 0; --j)
            {
                if (array[j] < array[j - 1])
                {
                    std::swap(array[j], array[j - 1]);
                }
            }
        }

        sortedSubArrayEndIndex++;
    }

    return array;
}
