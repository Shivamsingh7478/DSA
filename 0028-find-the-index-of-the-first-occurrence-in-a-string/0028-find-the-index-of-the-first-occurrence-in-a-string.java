class Solution {
    public int strStr(String haystack, String needle) {
        int n = haystack.length();
        int m = needle.length();

        // if needle is longer than haystack, it cannot occur
        if (m > n) return -1;

        // try each possible starting index i
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            // compare haystack[i + j] with needle[j]
            while (j < m && haystack.charAt(i + j) == needle.charAt(j)) {
                j++;
            }
            if (j == m) {
                // matched all characters of needle
                return i;
            }
        }

        return -1;
    }
}