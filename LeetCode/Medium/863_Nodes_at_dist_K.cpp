
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void markParents(TreeNode *root,
                     unordered_map<TreeNode *, TreeNode *> &parent_track)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *Node = q.front();
            q.pop();

            if (Node->left)
            {
                q.push(Node->left);
                parent_track[Node->left] = Node;
            }

            if (Node->right)
            {
                q.push(Node->right);
                parent_track[Node->right] = Node;
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        markParents(root, parent_track);
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;

        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while (!q.empty())
        {
            int size = q.size();
            if (curr_level++ == k)
                break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *Node = q.front();
                q.pop();

                if (Node->left && !visited[Node->left])
                {
                    q.push(Node->left);
                    visited[Node->left] = true;
                }

                if (Node->right && !visited[Node->right])
                {
                    q.push(Node->right);
                    visited[Node->right] = true;
                }

                if (parent_track[Node] && !visited[parent_track[Node]])
                {
                    q.push(parent_track[Node]);
                    visited[parent_track[Node]] = true;
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};
