class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int maxi = INT_MIN;
        
         

        for(int i=0; i<n;i++)
        {
            
            int compare = n-i;
           
            if(citations[i] >= compare)
            {
                maxi = max(maxi, compare);
                cout<< maxi << endl;
            }
        }
        if(maxi == INT_MIN)
         {
          return 0;
         }
        return maxi;
    }
};