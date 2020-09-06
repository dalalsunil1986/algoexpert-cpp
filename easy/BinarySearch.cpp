#include <vector>

int binarySearchHelper(std::vector<int> array, int target, int leftIndex, int rightIndex)
{
    if (leftIndex > rightIndex)
    {
        return -1;
    }

    int midIndex = (leftIndex + rightIndex) / 2;
    int midValue = array[midIndex];

    if (target == midValue)
    {
        return midIndex;
    }
    else if (target > midValue)
    {
        return binarySearchHelper(array, target, midIndex + 1, rightIndex);
    }
    else
    {
        return binarySearchHelper(array, target, leftIndex, midIndex - 1);
    }
}

int binarySearch(std::vector<int> array, int target)
{
    return binarySearchHelper(array, target, 0, array.size() - 1);
}