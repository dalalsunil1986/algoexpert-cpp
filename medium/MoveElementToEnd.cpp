#include <vector>

std::vector<int> moveElementToEnd(std::vector<int> array, int toMove)
{
    int currentIndex = 0;
    int placeToMove = array.size() - 1;

    while (currentIndex < placeToMove)
    {
        while (array[placeToMove] == toMove && currentIndex < placeToMove)
        {
            placeToMove--;
        }

        if (array[currentIndex] == toMove)
        {
            std::swap(array[placeToMove], array[currentIndex]);
        }

        currentIndex++;
    }

    return array;
}
