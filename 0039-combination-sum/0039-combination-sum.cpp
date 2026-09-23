class Solution {
public:
    void func(int n, vector<int>& candidates, int idx, int target,
              vector<int>& diary, vector<vector<int>>& res, int sum) {

        if (idx == n) {

            if (sum == target) {
                res.push_back(diary);
            }

            return;
        }

        // nai levu
        func(n, candidates, idx + 1, target, diary, res, sum);

        // levu che to 2 condition repeat aj index until sum + a[index] > target

        if (sum + candidates[idx] <= target) {
            diary.push_back(candidates[idx]);
            sum = sum + candidates[idx];

            func(n, candidates, idx, target, diary, res, sum);

            diary.pop_back();
            sum = sum - candidates[idx];
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        vector<int> diary;
        vector<vector<int>> res;
        int idx = 0;
        func(n, candidates, idx, target, diary, res, sum);

        return res;
    }
};