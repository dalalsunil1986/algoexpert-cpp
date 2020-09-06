#include <algorithm>
#include <vector>

class BST
{
public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

int findClosestValueInBst(BST* tree, int target)
{
    std::vector<int> values{tree->value};

    if (tree->left)
    {
        int valueFromLeft = findClosestValueInBst(tree->left, target);
        values.push_back(valueFromLeft);
    }

    if (tree->right)
    {
        int valueFromRight = findClosestValueInBst(tree->right, target);
        values.push_back(valueFromRight);
    }

    return *std::min_element(values.begin(), values.end(),
                             [&](int i, int j) { return abs(i - target) < abs(j - target); });
}
