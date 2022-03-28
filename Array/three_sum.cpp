class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answ;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size()-2; i++) {
            if (i > 0 and nums[i] == nums[i-1]) {
                continue;
            }
            
            int start_val = nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
                if (start_val + nums[l] + nums[r] == 0) {
                    answ.push_back(vector<int>{start_val, nums[l], nums[r]});
                    cout << start_val << endl;
                    l += 1;
                    while (l < r and nums[l] == nums[l-1]) {
                        l += 1;
                    }
                }
                else if (start_val + nums[l] + nums[r] > 0) {
                    r -= 1;
                }
                else {
                    l += 1;
                }
            }
        }
        return answ;
    }
};