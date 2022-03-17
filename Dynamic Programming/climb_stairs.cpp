class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }
        else if (dp[n] != -1) {
            return dp[n];
        }
        else {
            dp[n] = solve(n-1, dp) + solve(n-2, dp);  // Fibonacci sequence
        }
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};