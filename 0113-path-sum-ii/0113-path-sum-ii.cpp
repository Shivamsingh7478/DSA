/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int>& current, vector<vector<int>>& allPaths)
    {
        if(root == NULL)
        {
            return;
        }

        current.push_back(root->val);

        targetSum -= root->val;

        if(root->left == NULL && root->right == NULL && targetSum == 0)
        {
            allPaths.push_back(current);
        }
        else
        {
            solve(root->left, targetSum, current, allPaths);
            solve(root->right, targetSum, current, allPaths);
        }

        current.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>current;
        vector<vector<int>> allPaths;
        solve(root, targetSum, current, allPaths);
        return allPaths;
    }
};