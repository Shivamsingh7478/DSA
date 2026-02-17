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
    public void storeinorder(TreeNode root, List<Integer> inorder)
    {
       if(root == null)
       {
        return; 
       }


       storeinorder(root.left, inorder);
       inorder.add(root.val);
       storeinorder(root.right, inorder);
    }

    public boolean checkTarget(List<Integer> arr, int k)
    {
        int size = arr.size();
        int s = 0;
        int e = size-1;

        while(s<e)
        {
            int sum = arr.get(s) + arr.get(e);
            if(sum == k)
            {
                return true;
            }

            if(sum < k)
            {
                s++;
            }
            if(sum > k)
            {
                e--;
            }


        }

        return false;
    }
    
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> array = new ArrayList<>();
        storeinorder(root, array);
        boolean ans = checkTarget(array, k);
        return ans;
    }
}