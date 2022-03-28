class Solution {
public:
    bool simulate(int i, int j, vector<vector<int>>& heights) {
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> queue;
        queue.push_back(vector<int>{i, j});

        set<tuple<int, int>> seen;
        seen.insert(make_tuple(i, j));

        bool pacific = false;
        bool atlantic = false;

        while (queue.size() != 0) {
            vector<vector<int>> next_queue;
            for (int i = 0; i < queue.size(); i++) {
                cout << queue[i];
                int curr_i = queue[i][0];
                int curr_j = queue[i][1];

                for (auto& direction : directions) {
                    int next_i = curr_i + direction[0];
                    int next_j = curr_j + direction[1];
                    if (next_i == -1 or next_j == -1) {
                        pacific = true;
                        if (pacific == true and atlantic == true) {
                            return true;
                        }
                        continue;
                    }
                    if (next_i == heights.size() or next_j = heights[0].size()) {
                        atlantic = true;
                        if (pacific == true and atlantic == true) {
                            return true;
                        }
                        continue;
                    }
                    if (seen.find(make_tuple(next_i, next_j)) == seen.end()) {
                        next_queue.push_back(vector<int>{next_i, next_j});
                        seen.insert(make_tuple(next_i, next_j));
                    }
                }
            }
            queue = next_queue;
        }
        return false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answ;

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (simulate(i, j, heights)) {
                    answ.push_back(vector<int>{i, j});
                }
            }
        }
        return answ;
    }
};