
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

int nodeDepthsHelper(BinaryTree* root, int currentLevel)
{
    if (root == nullptr)
    {
        return 0;
    }

    return currentLevel + nodeDepthsHelper(root->left, currentLevel + 1) +
           nodeDepthsHelper(root->right, currentLevel + 1);
}

int nodeDepths(BinaryTree* root)
{
    return nodeDepthsHelper(root, 0);
}