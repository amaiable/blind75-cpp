class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int answ = 0;
        for (int i = 0; i < nums.size(); i++) {
            answ ^= i ^ nums[i];
        }
        return answ ^ nums.size();
    }
};