#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& ans, int color, int iniColor,
             vector<vector<int>>& image, int dr[], int dc[]) {
        ans[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                image[nr][nc] == iniColor && ans[nr][nc] != color) {
                dfs(nr, nc, ans, color, iniColor, image, dr, dc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, color, iniColor, image, dr, dc);
        return ans;
    }
};