class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }
        
        vector<int> suffix(nums.size());
        suffix[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i > -1; i--) {
            suffix[i] = suffix[i+1] * nums[i];
        }
        
        vector<int> answ(nums.size());
        answ[0] = suffix[1];
        answ[nums.size()-1] = prefix[nums.size()-2];
        for (int i = 1; i < nums.size() - 1; i++) {
            answ[i] = prefix[i-1] * suffix[i+1];
        }
        
        return answ;
    }
};