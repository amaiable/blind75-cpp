class Solution {
public:
    int solve(int t1, int t2, string& text1, string& text2, vector<vector<int>>& dp) {
        if (t1 == text1.size() or t2 == text2.size()) {
            return 0;
        }
        else if (dp[t1][t2] != -1) {
            return dp[t1][t2];
        }
        else {
            int answ = 0;
            if (text1[t1] == text2[t2]) {
                answ = max(answ, 1 + solve(t1+1, t2+1, text1, text2, dp));
            }
            else {
                answ = max(solve(t1+1, t2, text1, text2, dp), solve(t1, t2+1, text1, text2, dp));
            }
            dp[t1][t2] = answ;
        }
        return dp[t1][t2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));

        return solve(0, 0, text1, text2, dp);
    }
};