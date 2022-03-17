class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0;
        }
        else if (dp[i] != -1) {
            return dp[i];
        }
        else {
            dp[i] = max(nums[i] + solve(i+2, nums, dp), solve(i+1, nums, dp));
        }
        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        return solve(0, nums, dp);
    }
};