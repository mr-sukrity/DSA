class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
         int m = mat.size();          // number of rows in original matrix
        int n = mat[0].size();       // number of columns in original matrix

        // If total elements don't match, return original matrix
        if (m * n != r * c) return mat;

        vector<vector<int>> result(r, vector<int>(c));
        int row = 0, col = 0;

        // Traverse original matrix in row-major order
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[row][col] = mat[i][j];
                col++;
                if (col == c) {   // move to next row in reshaped matrix
                    col = 0;
                    row++;
                }
            }
        }
        return result;
    }
};