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

        int leftH = getHieght(root->left);
        int rightH = getHieght(root->right);

        int Hieght = max(leftH, rightH);

        int totalHieght = Hieght +1;

        return totalHieght;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }

        int lh = getHieght(root->left);
        int rh = getHieght(root->right);
        int absltDiff = abs(lh-rh);
        bool status = (absltDiff <= 1);

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(status && left && right)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};