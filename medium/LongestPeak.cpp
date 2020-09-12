#include <vector>

int longestPeak(std::vector<int> array)
{
    if (array.size() < 3)
    {
        return 0;
    }

    int longestPeak = 0;
    int currentPeak = 1;
    bool peakIncreasing = false;
    bool peakDecreasing = false;

    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] > array[i - 1])
        {
            if (peakDecreasing)
            {
                if (currentPeak > longestPeak)
                {
                    longestPeak = currentPeak;
                }
                peakDecreasing = false;
                currentPeak = 1;
            }

            peakIncreasing = true;
            currentPeak++;
        }
        else if (array[i] < array[i - 1] && peakIncreasing)
        {
            peakDecreasing = true;
            currentPeak++;
        }
        else if (array[i] == array[i - 1])
        {
            if (peakIncreasing && peakDecreasing && currentPeak > longestPeak)
            {
                longestPeak = currentPeak;
            }
            peakIncreasing = false;
            peakDecreasing = false;
            currentPeak = 1;
        }
    }

    if (peakIncreasing && peakDecreasing && currentPeak > longestPeak)
    {
        longestPeak = currentPeak;
    }

    return longestPeak;
}
