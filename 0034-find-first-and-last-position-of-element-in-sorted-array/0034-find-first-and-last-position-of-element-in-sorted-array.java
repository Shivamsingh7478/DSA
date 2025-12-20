class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return new int[]{first, last};
    }

    private int findFirst(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;          // possible first
                right = mid - 1;    // keep searching left side
            } else if (nums[mid] < target) {
                left = mid + 1;     // go right
            } else {
                right = mid - 1;    // go left
            }
        }
        return ans;
    }

    private int findLast(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;          // possible last
                left = mid + 1;     // keep searching right side
            } else if (nums[mid] < target) {
                left = mid + 1;     // go right
            } else {
                right = mid - 1;    // go left
            }
        }
        return ans;
    }
}