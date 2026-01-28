#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;
        int cpint = 0;

        for (char x : tasks)
            freq[x]++;

        for (auto &it : freq)
        {
            pq.push({it.second, it.first});
        }

        while (!pq.empty())
        {
            vector<pair<int, char>> temp;
            int cycle = n + 1;

            while (cycle-- && !pq.empty())
            {
                pair<int, char> curr = pq.top();
                pq.pop();
                curr.first--;
                temp.push_back(curr);
                cpint++;
            }

            for (auto &p : temp)
            {
                if (p.first > 0)
                    pq.push(p);
            }

            if (!pq.empty())
            {
                cpint += cycle + 1;
            }
        }

        return cpint;
    }
};