#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        vector<int> rot;
        ListNode *temp = head;

        while (temp)
        {
            rot.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> res(rot.size());

        for (int i = 0; i < rot.size(); i++)
        {
            res[(i + k) % rot.size()] = rot[i];
        }

        ListNode *NewHead = NULL;
        ListNode *NewTail = NULL;

        for (int i = 0; i < res.size(); i++)
        {
            ListNode *tp = new ListNode(res[i]);
            if (!NewHead)
            {
                NewHead = tp;
                NewTail = tp;
            }

            else
            {
                NewTail->next = tp;
                NewTail = NewTail->next;
            }
        }

        return NewHead;
    }
};