class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;

        for(int i=0;i<k;i++)
        {
            int element = nums[i];


            while(!q.empty() && nums[q.back()] < element)
            {
                q.pop_back();
            }
            q.push_back(i);
        }

        int index = q.front();
        int element = nums[index];
        ans.push_back(element);


        for(int i=k;i<nums.size();i++)
        {
            if(q.front() < i-k+1)
            {
                q.pop_front();

            }

             int element = nums[i];


            while(!q.empty() && nums[q.back()] < element)
            {
                q.pop_back();
            }
            q.push_back(i);


            int index = q.front();
            int anselement = nums[index];
            ans.push_back(anselement);
        }

        return ans;
    }
};