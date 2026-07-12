class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=m*n-1;
        while(low<=high){
           int mid=(low+high)/2;
          int  row=mid/n;
           int colomn=mid%n;
            if(matrix[row][colomn]==target) return true;
            else if(matrix[row][colomn]<target) low=mid+1;
            else high=mid-1;
            }
        return false;
    }
};   //first assume 2D array is 1D array.....thenn convert 1D to2D again ...and apply binary search because TC is given in the qs.