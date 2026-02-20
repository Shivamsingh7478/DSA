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
    public void inOrder(TreeNode root, List<Integer> arr)
    {
        if(root == null)
        {
            return;
        }

        inOrder(root.left, arr);
        arr.add(root.val);
        inOrder(root.right, arr);
    }

     public void updateTree(TreeNode root, List<Integer> arr, int[] index) {
        if (root == null) {
            return;
        }

        updateTree(root.left, arr, index);
        root.val = arr.get(index[0]);  // ✅ use get()
        index[0]++;                   // ✅ correct index handling
        updateTree(root.right, arr, index);
    }
    public TreeNode bstToGst(TreeNode root) {
        if(root == null)
        {
            return null;
        }

        if(root.left == null && root.right == null)
        {
            return root;
        }

        //step 1 is to make inorder
        List<Integer> array = new ArrayList<>();

        inOrder(root, array);


        // step 2 addition
        Integer n = array.size();
        for(int i = n-1;i>=0;i--)
        {
            Integer currVal = array.get(i);
            Integer nextVal = 0;

            if(i+1 < n)
            {
                nextVal = array.get(i+1);
            }

            Integer sum = currVal + nextVal;
            array.set(i, sum);
        }

        int[] index = new int[1];   // acts like pass-by-reference
        updateTree(root, array, index);
        return root;


    }
}