class Solution {
public:
    bool isValid(string s) {
        // if(s.size() == 0)
        // {
        //     return true;

        // }

        // int fnd = s.find("abc");

        // if(fnd != string::npos)
        // {
        //     string left = s.substr(0, fnd);
        //     string right = s.substr(fnd+3, s.size());
        //     return isValid(left+right);
        // }

        // return false;


        if(s[0] != 'a')
        {
            return false;

        }
        stack<char> st;
        for(char ch:s)
        {
            if(ch == 'a')
            {
                st.push('a');
            }
           else if(ch == 'b')
           {
            if(!st.empty() && st.top() == 'a')
            {
                st.push('b');
            }
            else
            {
                return false;
            }
           }

           else{
            if(!st.empty() && st.top() == 'b')
            {
                st.pop();
                if(!st.empty() && st.top() == 'a')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else{
                return false;
            }
           }
        }

        if(st.empty())
        {
            return true;
        }

        return false;
    }
};