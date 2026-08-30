class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {

        // 1. If node is NULL
        if (root == NULL) {
            return;
        }

        // 2. Add current node
        path.push_back(root->val);

        // 3. Check leaf node
        if (root->left == NULL && root->right == NULL) {

            // 4. Check target sum
            if (targetSum == root->val) {
                ans.push_back(path);
            }
        }

        // 5. Go left
        dfs(root->left, targetSum - root->val);

        // 6. Go right
        dfs(root->right, targetSum - root->val);

        // 7. Backtracking
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        dfs(root, targetSum);

        return ans;
    }
};