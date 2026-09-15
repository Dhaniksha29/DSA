class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (candidates[i] > target)
                continue;

            current.push_back(candidates[i]);


            solve(candidates, target - candidates[i], i, current, ans);


            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};