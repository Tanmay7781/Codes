#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> vals;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *temp = lists[i];

            while (temp)
            {
                vals.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(vals.begin(), vals.end());

        ListNode *Head = NULL;
        ListNode *tail = NULL;
        ListNode *temp = NULL;

        for (int i = 0; i < vals.size(); i++)
        {
            ListNode *temp = new ListNode(vals[i]);

            if (Head == NULL)
            {
                Head = temp;
                tail = temp;
            }

            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        return Head;
    }
};