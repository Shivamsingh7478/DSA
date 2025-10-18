/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHieght(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftTree = getHieght(root->left);
        int rightTree = getHieght(root->right);
        int maxHieght = max(leftTree, rightTree);
        int totalHieght = maxHieght + 1;
        return totalHieght;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int leftTree = diameterOfBinaryTree(root->left);
        int rightTree = diameterOfBinaryTree(root->right);
        int option3 = getHieght(root->left) + getHieght(root->right);
        int maxTree = max(leftTree, max(rightTree, option3));
        return maxTree;
        
    }
};