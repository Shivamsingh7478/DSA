class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";

        String first = strs[0];

        for (int i = 0; i < first.length(); i++) {
            char c = first.charAt(i);
            // compare this char with same position in all other strings
            for (int j = 1; j < strs.length; j++) {
                // if index out of bounds or mismatch, return prefix till i
                if (i >= strs[j].length() || strs[j].charAt(i) != c) {
                    return first.substring(0, i);
                }
            }
        }
        // whole first string is common prefix
        return first;
    }
}