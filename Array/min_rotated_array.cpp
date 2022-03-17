class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;  // We'll use inclusive binary search
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {  // If this is the case, the answer is definitely not m, so lower boundary is now m + 1
                l = m + 1;
            }
            else {
                r = m;  // m could be the answer
            }
        }
        return nums[l];  // Exits when equal, can return l or h
    }
};