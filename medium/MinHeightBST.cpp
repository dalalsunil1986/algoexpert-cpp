#include <vector>

class BST
{
public:
    int value;
    BST* left;
    BST* right;

    BST(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value)
    {
        if (value < this->value)
        {
            if (left == nullptr)
            {
                left = new BST(value);
            }
            else
            {
                left->insert(value);
            }
        }
        else
        {
            if (right == nullptr)
            {
                right = new BST(value);
            }
            else
            {
                right->insert(value);
            }
        }
    }
};

BST* minHeightBstHelper(BST* root, std::vector<int>&& array)
{
    if (array.empty())
    {
        return root;
    }

    int midIndex = array.size() / 2;
    int midElement = array[midIndex];
    if (root == nullptr)
    {
        root = new BST(midElement);
    }
    else
    {
        root->insert(midElement);
    }

    minHeightBstHelper(root, std::vector<int>(array.begin(), array.begin() + midIndex));
    minHeightBstHelper(root, std::vector<int>(array.begin() + midIndex + 1, array.end()));
    return root;
}

BST* minHeightBst(std::vector<int> array)
{
    return minHeightBstHelper(nullptr, std::move(array));
}