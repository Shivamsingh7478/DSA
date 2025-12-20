class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;

        int k = 1; // index to place next unique element

        for (int i = 1; i < nums.length; i++) {
            // when a new value is found, write it at position k
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k; // number of unique elements
    }
}