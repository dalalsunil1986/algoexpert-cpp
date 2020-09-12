#include <limits>

class BST
{
public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

bool validateBstHelper(BST* tree, int minValue, int maxValue)
{
    if (tree == nullptr)
    {
        return true;
    }

    if (tree->value < minValue || tree->value >= maxValue)
    {
        return false;
    }

    if (tree->left && not validateBstHelper(tree->left, minValue, tree->value))
    {
        return false;
    }

    if (tree->right && not validateBstHelper(tree->right, tree->value, maxValue))
    {
        return false;
    }

    return true;
}

bool validateBst(BST* tree)
{
    return validateBstHelper(tree, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}