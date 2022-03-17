class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 and n == 0) {
            return 1;
        }
        else if (dp[m][n] != -1) {
            return dp[m][n];
        }
        else {
            if (m == 0) {
                dp[m][n] = solve(m, n-1, dp);
            }
            else if (n == 0) {
                dp[m][n] = solve(m-1, n, dp);
            }
            else {
                dp[m][n] = solve(m-1, n, dp) + solve(m, n-1, dp);
            }
        }
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, dp);
    }
};