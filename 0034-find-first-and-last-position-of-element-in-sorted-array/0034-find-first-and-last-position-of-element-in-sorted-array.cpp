class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else {
                res[0] = mid;
                high = mid - 1; // finding first occurance of that target
            }
        }

        low = 0 , high = nums.size() -1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else{
                res[1] = mid; 
                low = mid + 1; // finding the last occurance of that target
            }
        }

        return res;
    }
};