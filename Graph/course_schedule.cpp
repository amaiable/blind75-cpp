class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj_list;
        for (int i = 0; i < numCourses; i++) {
            adj_list[i] = vector<int>();
        }

        vector<int> degrees(numCourses, 0);

        for (auto& course : prerequisites) {
            degrees[course[0]] += 1;
            adj_list[course[1]].push_back(course[0]);
        }

        vector<int> ready;

        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                ready.push_back(i);
            }
        }

        int answ = 0;

        while (ready.size() > 0) {
            int curr = ready[ready.size()-1];
            answ += 1;
            ready.pop_back();
            for (auto& nbr : adj_list[curr]) {
                degrees[nbr] -= 1;
                if (degrees[nbr] == 0) {
                    ready.push_back(nbr);
                }
            }
        }
        return answ == numCourses;
    }
};