/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // public void inOrder(TreeNode root, List<Integer> vector)
    // {
    //     if(root== null)
    //     {
    //         return;
    //     }

    //     inOrder(root.left, vector);
    //     vector.add(root.val);
    //     inOrder(root.right, vector);
    // }

    int count =0;
    TreeNode ans = null;
    public void solve(TreeNode root, int k)
    {
        if(root == null)
        {
            return;
        }

        solve(root.left, k);
        count++;
        if(count == k)
        {
            ans = root;
        }

        solve(root.right, k);
    }
    public int kthSmallest(TreeNode root, int k) {
        // List<Integer> arr = new ArrayList<>();
        // inOrder(root, arr);
        // return arr.get(k-1);
        
        solve(root, k);
        return ans.val;



    }
}