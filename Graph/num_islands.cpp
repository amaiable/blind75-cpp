class Solution {
public:
    bool valid(int i, int j, vector<vector<char>>& grid) {
        return i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size();
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& direction : directions) {
            int new_i = i + direction[0];
            int new_j = j + direction[1];

            if (valid(new_i, new_j, grid)) {
                if (grid[new_i][new_j] == '1') {
                    grid[new_i][new_j] = '0';
                    dfs(new_i, new_j, grid);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int answ = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    answ += 1;
                    dfs(i, j, grid);
                }
            }
        }
        return answ;
    }
};