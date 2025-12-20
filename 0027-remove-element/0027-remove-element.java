class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0;  // next position to place a kept element

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];  // copy kept element forward
                k++;
            }
        }

        return k;   // number of elements != val
    }
}