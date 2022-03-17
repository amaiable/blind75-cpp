class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i == nums.size()) {
            return 0;
        }
        else if (dp[i] != -1) {
            return dp[i];
        }
        else {
            int answ = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    answ = max(answ, 1 + solve(j, nums, dp));
                }
            }
            dp[i] = answ;
        }
        return dp[i];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        int answ = 0;
        for (int i = 0; i < nums.size(); i++) {
            answ = max(answ, 1 + solve(i, nums, dp));
        }
        return answ;
    }
};