#include <limits>
#include <vector>

std::vector<int> findThreeLargestNumbers(std::vector<int> array)
{
    int minimalInt = std::numeric_limits<int>::min();
    std::vector<int> largestNumbers = {minimalInt, minimalInt, minimalInt};

    for (int i : array)
    {
        if (i > largestNumbers[2])
        {
            largestNumbers[0] = largestNumbers[1];
            largestNumbers[1] = largestNumbers[2];
            largestNumbers[2] = i;
        }
        else if (i > largestNumbers[1])
        {
            largestNumbers[0] = largestNumbers[1];
            largestNumbers[1] = i;
        }
        else if (i > largestNumbers[0])
        {
            largestNumbers[0] = i;
        }
    }

    return largestNumbers;
}
