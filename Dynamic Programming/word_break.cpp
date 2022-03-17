class Solution {
public:
    int solve(int i, string& s, unordered_set<string>& wordSet, vector<int>& dp) {
        if (i == s.size()) {
            return 1;
        }
        else if (dp[i] != -1) {
            return dp[i];
        }
        else {
            string curr = "";
            for (int j = i; j < s.size(); j++) {
                curr += s[j];
                if (wordSet.find(curr) != wordSet.end() and solve(j+1, s, wordSet, dp)) {
                    dp[i] = 1;
                    return 1;
                }
            }
            dp[i] = 0;
            return 0;
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto& word : wordDict) {
            wordSet.insert(word);
        }

        vector<int> dp(s.size(), -1);

        return solve(0, s, wordSet, dp) == 1 ? true : false;
    }
};