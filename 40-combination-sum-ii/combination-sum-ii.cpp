class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        function<void(int, int)> solve = [&](int start, int target) {

            if (target == 0) {
                ans.push_back(temp);
                return;
            }

            if (target < 0)
                return;

            for (int i = start; i < candidates.size(); i++) {

                // Skip duplicate numbers at the same level
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;

                // If number is too large
                if (candidates[i] > target)
                    break;

                // Choose
                temp.push_back(candidates[i]);

                // i + 1 → number can be used only once
                solve(i + 1, target - candidates[i]);

                // Backtrack
                temp.pop_back();
            }
        };

        solve(0, target);

        return ans;
    }
};