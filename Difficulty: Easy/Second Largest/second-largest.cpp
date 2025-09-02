class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        // stack<int> st;
        
        // int min = INT_MIN;
        // int max =INT_MIN;
        int second = INT_MIN;
        int first =INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>first)
            {
                second = first;
                first = arr[i];
            }
            
            else if(arr[i] > second && arr[i]!=first)
            {
                second = arr[i];
            }
            
        }
        if(second == INT_MIN)
        {
            return -1;
        }
        
        
        
        
        return second;
    }
};