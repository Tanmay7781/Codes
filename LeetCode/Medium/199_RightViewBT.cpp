#include <vector>

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
    void traverse(TreeNode *node, int level, vector<int> &res)
    {
        if (!node)
            return;

        if (level == res.size())
            res.push_back(node->val);

        traverse(node->right, level + 1, res);
        traverse(node->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        traverse(root, 0, res);
        return res;
    }
};