class Solution {
public:
         // Rotate matrix 90 degrees clockwise
    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
         for (int k = 0; k < 4; k++) {
            if (mat == target) return true;
            rotate90(mat);
        }
        return false;

    }
};