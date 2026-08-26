class Solution {
public:

    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;

        for (int x = 1; x <= 1000; x++) {
            bool present = true;

            for (auto &arr : nums) {
                if (find(arr.begin(), arr.end(), x) == arr.end()) {
                    present = false;
                    break;
                }
            }

            if (present)
                ans.push_back(x);
        }

        return ans;
    }
};