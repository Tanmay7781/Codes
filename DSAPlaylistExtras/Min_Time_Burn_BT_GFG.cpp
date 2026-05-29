#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void parentPointer(Node* root, unordered_map<Node*, Node*>& parent_track, Node*& trgt, int target) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == target) {
                trgt = current;
            }

            if (current->left) {
                q.push(current->left);
                parent_track[current->left] = current;
            }

            if (current->right) {
                q.push(current->right);
                parent_track[current->right] = current;
            }
        }
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_track;
        Node* trgt = NULL;
        unordered_map<Node*, bool> burnt;
        queue<Node*> q;
        parentPointer(root, parent_track, trgt, target);
        int mintime = 0;

        q.push(trgt);
        burnt[trgt] = true;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                if (current->left && !burnt[current->left]) {
                    q.push(current->left);
                    burnt[current->left] = true;
                }

                if (current->right && !burnt[current->right]) {
                    q.push(current->right);
                    burnt[current->right] = true;
                }

                if (parent_track[current] && !burnt[parent_track[current]]) {
                    q.push(parent_track[current]);
                    burnt[parent_track[current]] = true;
                }
            }

            if (!q.empty())
                mintime++;
        }

        return mintime;
    }
};