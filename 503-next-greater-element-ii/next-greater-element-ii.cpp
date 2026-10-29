class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s; // stores indices

        for (int i = 0; i < 2 * n; i++) {  // circular array
            int idx = i % n;

            while (!s.empty() && nums[s.top()] < nums[idx]) {
                ans[s.top()] = nums[idx];
                s.pop();
            }

            if (i < n)
                s.push(idx);
        }

        return ans;
    }
};