class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            //now check close parenthesis
           else
           {
            //always remember to check empty stack or not
                if(ch == ')' && !st.empty() && st.top() == '(')
                {
                    st.pop();
                }

                else if(ch == '}' && !st.empty() && st.top() == '{')
                {
                    st.pop();
                }

                else if(ch == ']' && !st.empty() && st.top() == '[')
                {
                    st.pop();
                }

                else{
                    return false;
                }
           }

        }
        // check if it is empty or not
        if(st.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};