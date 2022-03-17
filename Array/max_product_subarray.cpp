class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int local_min = nums[0];
        int local_max = nums[0];
        int global_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int new_lmn = min(nums[i], min(local_min * nums[i], local_max * nums[i]));
            int new_lmx = max(nums[i], max(local_min * nums[i], local_max * nums[i]));
            local_min = new_lmn;
            local_max = new_lmx;
            global_max = max(global_max, local_max);
        }
        
        return global_max;
    }
};