class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack(res, new StringBuilder(), 0, 0, n);
        return res;
    }

    private void backtrack(List<String> res, StringBuilder curr,
                           int open, int close, int n) {

        // If current string has length 2*n, it's a complete combination
        if (curr.length() == 2 * n) {
            res.add(curr.toString());
            return;
        }

        // Option 1: add '(' if we still have opens left
        if (open < n) {
            curr.append('(');
            backtrack(res, curr, open + 1, close, n);
            curr.deleteCharAt(curr.length() - 1); // undo
        }

        // Option 2: add ')' if it won't make it invalid
        if (close < open) {
            curr.append(')');
            backtrack(res, curr, open, close + 1, n);
            curr.deleteCharAt(curr.length() - 1); // undo
        }
    }
}