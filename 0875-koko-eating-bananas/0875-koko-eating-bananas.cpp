class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int n = piles.size();
        int res= 0;
        int high = piles[0];
        for(int i = 1 ; i < n ; i++){
            if(piles[i] > piles[i-1]){
                high = max(high , piles[i]);
            }else{
                high =max(high ,  piles[i-1]);
            }
        }

        while(low <= high){
            int mid = (high + low)/2;

            long long hour = 0;
            for(int i = 0 ; i < n ; i++){
                hour = hour + piles[i]/mid;

                if(piles[i] % mid != 0)hour++;
            }

            if(hour > h)low = mid + 1;
            else{
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};