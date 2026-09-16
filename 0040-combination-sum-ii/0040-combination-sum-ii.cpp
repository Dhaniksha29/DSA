class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int, int)> backtrack = [&](int start, int target) {
            if (target == 0) {
                ans.push_back(temp);
                return;
            }

            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;

                if (candidates[i] > target)
                    break;

                temp.push_back(candidates[i]);
                backtrack(i + 1, target - candidates[i]);
                temp.pop_back();
            }
        };

        backtrack(0, target);
        return ans;
    }
};