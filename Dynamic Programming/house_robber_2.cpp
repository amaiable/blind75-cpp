class Solution {  // In hindsight, it might have been better if I made two separate vectors instead of two separate functions
public:
    int solvetf(int i, vector<int>& nums, vector<int>& dptf) {
        if (i >= nums.size()-1) {
            return 0;
        }
        else if (dptf[i] != -1) {
            return dptf[i];
        }
        else {
            dptf[i] = max(nums[i] + solvetf(i+2, nums, dptf), solvetf(i+1, nums, dptf));
        }
        return dptf[i];
    }

    int solventf(int i, vector<int>& nums, vector<int>& dpntf) {
        if (i >= nums.size()) {
            return 0;
        }
        else if (dpntf[i] != -1) {
            return dpntf[i];
        }
        else {
            dpntf[i] = max(nums[i] + solventf(i+2, nums, dpntf), solventf(i+1, nums, dpntf));
        }
        return dpntf[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dptf(nums.size(), -1);
        vector<int> dpntf(nums.size(), -1);
        
        if (nums.size() == 1) { // For edge case where there's only one element
            return nums[0];
        }

        return max(solvetf(0, nums, dptf), solventf(1, nums, dpntf));
    }
};