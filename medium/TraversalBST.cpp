#include <vector>

class BST
{
public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
};

std::vector<int> inOrderTraverseHelper(BST* tree, std::vector<int>& nodes)
{
    if (!tree)
    {
        return {};
    }

    if (tree->left)
    {
        inOrderTraverseHelper(tree->left, nodes);
    }

    nodes.push_back(tree->value);

    if (tree->right)
    {
        inOrderTraverseHelper(tree->right, nodes);
    }

    return nodes;
}

std::vector<int> inOrderTraverse(BST* tree, std::vector<int> array)
{
    return inOrderTraverseHelper(tree, array);
}

std::vector<int> preOrderTraverseHelper(BST* tree, std::vector<int>& nodes)
{
    if (!tree)
    {
        return {};
    }

    nodes.push_back(tree->value);

    if (tree->left)
    {
        preOrderTraverseHelper(tree->left, nodes);
    }

    if (tree->right)
    {
        preOrderTraverseHelper(tree->right, nodes);
    }

    return nodes;
}

std::vector<int> preOrderTraverse(BST* tree, std::vector<int> array)
{
    return preOrderTraverseHelper(tree, array);
}

std::vector<int> postOrderTraverseHelper(BST* tree, std::vector<int>& nodes)
{
    if (!tree)
    {
        return {};
    }

    if (tree->left)
    {
        postOrderTraverseHelper(tree->left, nodes);
    }

    if (tree->right)
    {
        postOrderTraverseHelper(tree->right, nodes);
    }

    nodes.push_back(tree->value);

    return nodes;
}

std::vector<int> postOrderTraverse(BST* tree, std::vector<int> array)
{
    return postOrderTraverseHelper(tree, array);
}