#include <vector>

class BinaryTree
{
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

std::vector<int> branchSums(BinaryTree* root)
{
    std::vector<int> result;
    if (!root->right && !root->left)
    {
        result.push_back(root->value);
        return result;
    }

    if (root->left)
    {
        auto vec = branchSums(root->left);
        result.insert(result.end(), vec.begin(), vec.end());
    }

    if (root->right)
    {
        auto vec = branchSums(root->right);
        result.insert(result.end(), vec.begin(), vec.end());
    }

    for (auto& r : result)
    {
        r += root->value;
    }

    return result;
}