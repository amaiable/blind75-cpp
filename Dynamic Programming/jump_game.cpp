class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i + nums[i] >= nums.size() - 1) {
            return 1;
        }
        else if (dp[i] != -1) {
            return dp[i];
        }
        else {
            for (int j = nums[i]; j > 0; j--) {
                if (solve(i+j, nums, dp) == 1) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        if (dp[i] == -1) {
            dp[i] = 0;
        }
        return dp[i];
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        return solve(0, nums, dp) == 1 ? true : false;
    }
};