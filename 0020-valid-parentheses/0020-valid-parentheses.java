class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {

            // 1. If opening bracket → push
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                // 2. If closing bracket → stack must not be empty
                if (stack.isEmpty()) {
                    return false;
                }

                char top = stack.pop();  // latest opening bracket

                // 3. Check if types match
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }

        // 4. All opening brackets must be matched
        return stack.isEmpty();
    }
}