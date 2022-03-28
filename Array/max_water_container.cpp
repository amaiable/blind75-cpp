class Solution {
public:
    int calculate_height(int i, int j, vector<int>& height) {
        return min(height[i], height[j]) * (j - i);
    }

    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int answ = 0;

        while (l < r) {
            answ = max(answ, calculate_height(l, r, height));

            if (height[l] < height[r]) {
                l += 1;
            }
            else {
                r -= 1;
            }
        }
        return answ;
    }
};