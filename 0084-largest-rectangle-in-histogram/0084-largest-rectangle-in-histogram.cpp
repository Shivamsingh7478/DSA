class Solution {
public:
    void prevSmallElement(vector<int> heights, vector<int> &prev)
    {
        stack<int> st;
        st.push(-1);

        for(int i=0;i<heights.size();i++)
        {
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element)
            {
                st.pop();
            }

            prev.push_back(st.top());
            st.push(i);
        }
    }

    void nextSmallElement(vector<int> heights, vector<int> &next)
    {
        stack<int> st;
        st.push(-1);

        for(int i=heights.size() -1;i>=0;i--)
        {
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element)
            {
                st.pop();
            }

            next.push_back(st.top());
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next;
        vector<int> prev;
        nextSmallElement(heights, next);
        reverse(next.begin(), next.end());
        //yaad rkhna ki -1 to 6 krna tavi jaa ke shi widht milega  n-p-1
        for(int i=0;i<next.size();i++)
        {
            if(next[i] == -1)
            {
                next[i] = next.size();
            }
        }
        prevSmallElement(heights, prev);
        
        int maxArea = INT_MIN;
        for(int i=0;i<next.size();i++)
        {
            int width = next[i] - prev[i] -1;
            int height = heights[i];
            int currentArea = width * height;
            maxArea = max(maxArea, currentArea);
        }

        return maxArea;

    }
};