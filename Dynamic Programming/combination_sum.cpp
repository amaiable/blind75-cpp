class Solution {
public:
    int solve(int target, vector<int>& nums, vector<int>& dp) {
        if (target == 0) {
            return 1;
        }
        else if (target < 0) {
            return 0;
        }
        else if (dp[target] != -1) {
            return dp[target];
        }
        else {
            int answ = 0;
            for (auto& num : nums) {
                answ += solve(target-num, nums, dp);
            }
            dp[target] = answ;
        }
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);

        return solve(target, nums, dp);
    }
};