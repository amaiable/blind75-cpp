class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {  // Using transpose and reflect approach from linear algebra
        // Transpose
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // Reflect
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size() / 2; j++) {
                int j_2 = matrix.size() - j - 1;
                int temp = matrix[i][j_2];
                matrix[i][j_2] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};