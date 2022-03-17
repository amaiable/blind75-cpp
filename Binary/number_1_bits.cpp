class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answ = 0;
        while (n > 0) {
            if (n % 2 != 0) {
                answ += 1;
            }
            n /= 2;
        }
        return answ;
    }
};