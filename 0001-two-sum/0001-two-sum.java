class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>(); // value -> index

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            if (map.containsKey(complement)) {
                // found the pair: nums[i] + nums[prevIndex] = target
                return new int[]{map.get(complement), i};
            }

            map.put(nums[i], i);
        }

        // As per problem, there is exactly one solution, so this won't really hit.
        return new int[]{-1, -1};
    }
}