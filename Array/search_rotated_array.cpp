class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] >= nums[l]) {  // Check the left part
                if (target >= nums[l] and target <= nums[m]) {  // Target is in left part
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else if (nums[m] < nums[l]) {  // Check the right part
                if (target >= nums[m] and target <= nums[r]) { // Target is in right part
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};