#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";

        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *Node = q.front();
            q.pop();
            if (Node == NULL)
                s.append("#,");
            else
                s.append(to_string(Node->val) + ',');
            if (Node != NULL)
            {
                q.push(Node->left);
                q.push(Node->right);
            }
        }
        return s;
    }

    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        queue<TreeNode *> q;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);

        while (!q.empty())
        {
            TreeNode *Node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
            {
                Node->left = NULL;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                Node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                Node->right = NULL;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                Node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};