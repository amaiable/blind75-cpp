class Solution {
public:
    bool valid(int i, int j, vector<vector<char>>& board) {  // Passes everything but TLEs ??
        return i >= 0 and j >= 0 and i < board.size() and j < board[0].size();
    }

    bool solve(int i, int j, int ind, set<pair<int, int>>& seen, vector<vector<char>>& board, string& word, vector<vector<int>>& dirs) {
        if (ind == word.size()) {
            return true;
        }
        else {
            for (auto& dir : dirs) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if (valid(new_i, new_j, board) and board[new_i][new_j] == word[ind] and seen.find(pair<int, int>(new_i, new_j)) == seen.end()) {
                    seen.insert(pair<int, int>(new_i, new_j));
                    if (solve(new_i, new_j, ind+1, seen, board, word, dirs)) {
                        return true;
                    }
                    seen.erase(pair<int, int>(new_i, new_j));
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    set<pair<int, int>> seen;
                    seen.insert(pair<int, int>(i, j));
                    if (solve(i, j, 1, seen, board, word, dirs)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};