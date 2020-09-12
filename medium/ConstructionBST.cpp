#include <vector>

class BST
{
public:
    int value;
    BST* left;
    BST* right;

    BST(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    BST& insert(int numberToInsert)
    {
        if (numberToInsert < value)
        {
            if (left == nullptr)
            {
                left = new BST(numberToInsert);
                return *left;
            }
            return left->insert(numberToInsert);
        }
        else
        {
            if (right == nullptr)
            {
                right = new BST(numberToInsert);
                return *right;
            }
            return right->insert(numberToInsert);
        }
        return *this;
    }

    bool contains(int numberToFind)
    {
        if (numberToFind == value)
        {
            return true;
        }
        else if (numberToFind < value)
        {
            if (left == nullptr)
            {
                return false;
            }
            return left->contains(numberToFind);
        }
        else
        {
            if (right == nullptr)
            {
                return false;
            }

            return right->contains(numberToFind);
        }
    }

    BST* findMinElementParent()
    {
        BST* temp = this;
        while (temp && temp->left && temp->left->left)
        {
            temp = temp->left;
        }
        return temp;
    }

    BST& remove(int numberToRemove, BST* parent = nullptr, bool rightBranch = false)
    {
        if (numberToRemove == value)
        {
            if (left && right)
            {
                if (BST* minElementParentOnRightBranch = right->findMinElementParent())
                {
                    if (minElementParentOnRightBranch->left)
                    {
                        int minElementValue = minElementParentOnRightBranch->left->value;
                        minElementParentOnRightBranch->left->remove(minElementValue,
                                                                    minElementParentOnRightBranch, false);
                        value = minElementValue;
                    }
                    else
                    {
                        int minElementValue = minElementParentOnRightBranch->value;
                        right->remove(minElementValue, this, true);
                        value = minElementValue;
                    }
                }
                return *this;
            }
            else if (left)
            {
                value = left->value;
                right = left->right;
                left = left->left;
            }
            else if (right)
            {
                value = right->value;
                left = right->left;
                right = right->right;
            }
            else
            {
                if (parent)
                {
                    if (rightBranch)
                    {
                        parent->right = nullptr;
                    }
                    else
                    {
                        parent->left = nullptr;
                    }
                }
            }
        }
        else if (numberToRemove < value)
        {
            if (left != nullptr)
            {
                return left->remove(numberToRemove, this, false);
            }
        }
        else
        {
            if (right != nullptr)
            {
                return right->remove(numberToRemove, this, true);
            }
        }
        return *this;
    }
};
