#include <vector>

bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence)
{
    if (sequence.empty())
    {
        return false;
    }

    int counter = 0;
    for (int i : array)
    {
        if (sequence[counter] == i)
        {
            counter++;
        }
    }

    return counter == sequence.size();
}
