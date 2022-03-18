class Solution {
public:
    bool valid(int i, int j, vector<vector<int>>& matrix) {
        return i >= 0 and j >= 0 and i < matrix.size() and j < matrix[0].size();
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

        vector<int> answ;
        
        set<pair<int, int>> seen;  // Cannot use unordered_set with pairs or tuples apparently

        int i = 0;
        int j = 0;

        int dir = 0;
        answ.push_back(matrix[0][0]);
        seen.insert(pair<int, int>(0, 0));

        while (answ.size() < matrix.size() * matrix[0].size()) {
            while (valid(i+dirs[dir][0], j+dirs[dir][1], matrix) and seen.find(pair<int, int>(i+dirs[dir][0], j+dirs[dir][1])) == seen.end()) {
                i += dirs[dir][0];
                j += dirs[dir][1];
                answ.push_back(matrix[i][j]);
                seen.insert(pair<int, int>(i, j));
            }
            dir += 1;
            dir %= 4;
        }


        return answ;
    }
};