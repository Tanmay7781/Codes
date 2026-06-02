#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorder(TreeNode *root, int k, int &res, int &count)
    {
        if (root == NULL)
            return;

        inorder(root->left, k, res, count);
        count++;

        if (k == count)
            res = root->val;

        inorder(root->right, k, res, count);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int res = 0, count = 0;
        inorder(root, k, res, count);
        return res;
    }
};