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

    int leftHieght(TreeNode* root)
    {
        int count =0;
        while(root)
        {
            count++;
            //leftHieght(root->left);
            //i cant do this because then it will intialize count to 0
            root = root->left;
        }

        return count;
    }

    int rightHieght(TreeNode* root)
    {
        int count =0;
        while(root)
        {
            count++;
            //leftHieght(root->right);
            //i cant do this because then it will intialize count to 0
            root = root->right;
        }

        return count;
    }
    int countNodes(TreeNode* root) {
        int leftans = leftHieght(root);
        int rightans = rightHieght(root);

        if(leftans == rightans)
        {
            return (1 << leftans) - 1;
        }

        int leftcount = countNodes(root->left);
        int rightcount = countNodes(root->right);

        return 1+leftcount+rightcount;
    }
};