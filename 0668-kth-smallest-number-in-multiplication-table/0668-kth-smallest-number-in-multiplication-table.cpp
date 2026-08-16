class Solution {
public:
    int func(int m , int n , int mid){
        int count = 0;
        int row = m;
        int col = 1;

        while(row >= 1 && col <= n){
            int val = row * col;

            if(val <= mid){
                count += row ;
                col++;
            }else{
                row--;
            }
        }

        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        int res = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            int ans = func( m , n , mid);

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