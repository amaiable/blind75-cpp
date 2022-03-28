class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answ = 0;

        for (int i = 0; i < 32; i++) {
            answ <<= 1;
            if (n % 2 == 1) {
                answ += 1;
            } 
            n /= 2;
        }

        return answ;
    }
};