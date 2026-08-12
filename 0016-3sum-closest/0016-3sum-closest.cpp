class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int maxDiff = INT_MAX;
        int diff;
        int resSum;
        int sum;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                diff = abs(sum - target);
                if (maxDiff > diff) {
                    maxDiff = diff;
                    resSum = sum;
                }

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                }
            }
        }

        return resSum;
    }
};