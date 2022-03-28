class Solution {
public:
    int solve(int i, vector<int>& answ) {
        if (i == 0) {
            return 0;
        }
        else if (i == 1) {
            return 1;
        }
        else if (answ[i] != -1) {
            return answ[i];
        }
        else {
            if (i % 2 == 0) {
                answ[i] = solve(i >> 1, answ);
            }
            else {
                answ[i] = 1 + solve(i >> 1, answ);
            }
        }
        return answ[i];
    }

    vector<int> countBits(int n) {
        vector<int> answ(n+1, -1);

        for (int i = 0; i <= n; i++) {
            answ[i] = solve(i, answ);
        }

        return answ;
    }
};