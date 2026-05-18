#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if (!root)
            return res;

        string p;

        DFS(root, res, p);

        return res;
    }

    void DFS(TreeNode* root, vector<string>& res, string p) {

        if (!root->left && !root->right) {
            res.push_back(p + to_string(root->val));
            p.clear();
            return;
        }

        p = p + to_string(root->val) + "->";

        if (root->left)
            DFS(root->left, res, p);

        if (root->right)
            DFS(root->right, res, p);
    }
};

int main() {
    return 0;
}