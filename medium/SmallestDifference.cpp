#include <algorithm>
#include <limits>
#include <vector>

std::vector<int> smallestDifference(std::vector<int> arrayOne, std::vector<int> arrayTwo)
{
    std::sort(arrayOne.begin(), arrayOne.end());
    std::sort(arrayTwo.begin(), arrayTwo.end());

    int smallestDiff = std::numeric_limits<int>::max();
    std::vector<int> result;

    int oneIndex = 0;
    int twoIndex = 0;

    while (oneIndex < arrayOne.size() && twoIndex < arrayTwo.size())
    {
        int firstNum = arrayOne[oneIndex];
        int secondNum = arrayTwo[twoIndex];

        if (firstNum < secondNum)
        {
            oneIndex++;
        }
        else
        {
            twoIndex++;
        }

        int diff = abs(secondNum - firstNum);
        if (diff < smallestDiff)
        {
            smallestDiff = diff;
            result = {firstNum, secondNum};
        }
    }
    return result;
}