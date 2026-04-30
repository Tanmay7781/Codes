#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (!root)
            return false;

        if (!root->left && !root->right)
        {
            return true;
        }
        return false;
    }

    void addLeftBoundary(Node *root, vector<int> &res)
    {
        Node *cur = root->left;

        while (cur)
        {
            if (!isLeaf(cur))
                res.push_back(cur->data);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    void addLeavesBoundary(Node *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }

        if (root->left)
            addLeavesBoundary(root->left, res);
        if (root->right)
            addLeavesBoundary(root->right, res);
    }

    void addRightBoundary(Node *root, vector<int> &res)
    {
        Node *cur = root->right;
        vector<int> temp;

        while (cur)
        {
            if (!isLeaf(cur))
                temp.push_back(cur->data);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            res.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> res;

        if (!root)
            return res;

        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeavesBoundary(root, res);
        addRightBoundary(root, res);

        return res;
    }
};