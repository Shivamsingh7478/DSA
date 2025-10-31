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
    int searchInorderIndex(int element, vector<int>& inorder)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i] == element)
            {
                return i;
            }
        }

        return -1;
    }
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int &preOrderIndex, int inorderStart, int inorderEnd, int size) {
       if(preOrderIndex >= size){
        return NULL;
       }

       if(inorderStart > inorderEnd)
       {
        return NULL;
       }

       int element = preorder[preOrderIndex];
       preOrderIndex++;

       TreeNode* root = new TreeNode(element);

       int inOrderIndex = searchInorderIndex(element, inorder);

      root->left = construct(preorder, inorder, preOrderIndex, inorderStart, inOrderIndex - 1, size);
       root->right = construct(preorder, inorder, preOrderIndex, inOrderIndex + 1, inorderEnd, size);

       return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int inorderStart =0;
        int inorderEnd = inorder.size() - 1;
        int size = inorder.size();

        TreeNode* root = construct(preorder, inorder, preOrderIndex, inorderStart, inorderEnd, size);

        return root;
    }
};