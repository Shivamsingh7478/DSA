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
    int widthOfBinaryTree(TreeNode* root) {

        unsigned long long maxwidth = 0;
        if(!root){
            return maxwidth;
        }
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        while(!q.empty())
        {
            unsigned long long size = q.size();
            unsigned long long leftmost = q.front().second;
            unsigned long long rightmost = q.back().second;
            unsigned long long current = rightmost - leftmost +1;
            maxwidth = max(maxwidth, current);

            for(int i=0;i<size;i++)
            {
                auto front = q.front();
                q.pop();
                TreeNode* node = front.first;
                unsigned long long index = front.second;
                

                if(node->left)
                {
                    q.push({node->left, 2*index});
                }
                if(node->right)
                {
                    q.push({node->right, 2*index+1});
                }
            }
        }

        return maxwidth;
    }
};