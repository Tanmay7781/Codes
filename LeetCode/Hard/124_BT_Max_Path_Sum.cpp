#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }

    int maxPathDown(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lsum = max(0, maxPathDown(root->left, maxi));
        int rsum = max(0, maxPathDown(root->right, maxi));

        maxi = max(maxi, root->val + lsum + rsum);

        return root->val + max(lsum, rsum);
    }
};