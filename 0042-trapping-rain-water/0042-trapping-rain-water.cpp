class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int result = 0;

        int prefixSum[n];
        prefixSum[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = max(prefixSum[i - 1], height[i]);
        }

        int suffixSum[n];
        suffixSum[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = max(suffixSum[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            int leftMax = prefixSum[i];
            int rightMax = suffixSum[i];
            result += min(leftMax, rightMax) - height[i];
        }

        return result;
    }
};

