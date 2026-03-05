#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int> freq;
        for (char x : s)
            freq[x]++;

        auto cmp = [&freq](char a, char b) { return freq[a] < freq[b]; };

        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);

        for (auto& x : freq)
            pq.push(x.first);

        while (!pq.empty()) {
            char ch = pq.top();
            pq.pop();

            res.append(freq[ch], ch);
        }

        return res;
    }
};