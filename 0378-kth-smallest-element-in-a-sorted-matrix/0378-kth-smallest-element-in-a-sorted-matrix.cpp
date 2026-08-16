class Solution {
public:
    int func(vector<vector<int>> matrix , int n , int m , int mid){
        int count = 0;
        int row = n - 1;
        int col = 0;

        while(row >= 0 && col < m){
            if(matrix[row][col] <= mid){
                count += row + 1;
                col++;
            }else{
                row--;
            }
        }

        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = -1;
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];

        while(low <= high){
            int mid = (low + high)/2;

            int ans = func(matrix , n , m , mid);
            if(ans < k){
                low = mid + 1;
            }else{
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};