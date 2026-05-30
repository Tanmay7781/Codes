#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int val, TreeNode*& res) {
        if (!root)
            return;

        if (val > root->val) {
            dfs(root->right, val, res);
        }
        else if (val < root->val) {
            dfs(root->left, val, res);
        }
        else {
            res = root;
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = nullptr;
        dfs(root, val, res);
        return res;
    }
};