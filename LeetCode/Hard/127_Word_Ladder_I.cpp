#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int length = q.front().second;
            q.pop();
            if (word == endWord)
                return length;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (s.find(word) != s.end())
                    {
                        s.erase(word);
                        q.push({word, length + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};