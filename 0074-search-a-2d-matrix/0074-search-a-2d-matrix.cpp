class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m-1;
        int row = -1;
        

        while(low <= high){
            int mid = (low + high)/2;

            if(matrix[mid][0] <= target){
                row = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        if(row == -1) return false;
        int low2 = 0;
        int high2 = n-1;

        while(low2 <= high2){
            int mid2 = (low2 + high2)/2;

            if(matrix[row][mid2] == target){
                return true;
            }else if(matrix[row][mid2] < target){
                low2 = mid2 + 1;
            }else{
                high2 = mid2 -1;
            }
        }

        return false;
    }
};