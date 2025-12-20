class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> lastIndex = new HashMap<>();
        int maxLen = 0;
        int start = 0; // left boundary of current window

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            // if character seen and inside current window, move start
            if (lastIndex.containsKey(c) && lastIndex.get(c) >= start) {
                start = lastIndex.get(c) + 1;
            }

            lastIndex.put(c, i); // update last seen index
            maxLen = Math.max(maxLen, i - start + 1);
        }

        return maxLen;
    }
}