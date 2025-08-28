class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int j=0;
        int maxLen =0;
        //sliding window
        for(int i=0;i<s.size();i++)
        {
            while(st.find(s[i]) != st.end())
            {
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            maxLen = max(maxLen, (int)st.size());
        }
        return maxLen;
        // return st.size();
    }
};