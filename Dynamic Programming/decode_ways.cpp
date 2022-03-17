class Solution {
public:
    int solve(int i, string& s, vector<int>& dp) {
        if (i == s.size()) {
            return 1;
        }
        else if (s[i] == '0') {
            return 0;
        }
        else if (dp[i] != -1) {
            return dp[i];
        }
        else {
            int answ = 0;
            answ += solve(i+1, s, dp);  // Always works unless it's a zero, which we took care of above
            if (i < s.size() - 1 and stoi(s.substr(i, 2)) <= 26) {
                answ += solve(i+2, s, dp);
            }
            dp[i] = answ;
        }
        return dp[i];
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);

        return solve(0, s, dp);
    }
};