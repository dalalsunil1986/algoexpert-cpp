#include <any>
#include <vector>

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
int productSum(std::vector<std::any> array, int level = 1)
{
    int sum = 0;

    for (const auto& el : array)
    {
        if (el.type() == typeid(std::vector<std::any>))
        {
            sum += productSum(std::any_cast<std::vector<std::any>>(el), level + 1);
        }
        else
        {
            sum += std::any_cast<int>(el);
        }
    }
    return sum * level;
}
