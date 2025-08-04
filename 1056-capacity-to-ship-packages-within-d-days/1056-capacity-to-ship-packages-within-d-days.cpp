class Solution {
public:

    int findDays(vector<int> &arr, int cap)
    {
        int n=arr.size();
        int d=1;
        int load=0;

        for(int i=0;i<n;i++)
        {
           if(load + arr[i] > cap)
           {
            d+=1;
            load = arr[i];
           }

           else
           {
            load+=arr[i];
           }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(), weights.end());
        int e=accumulate(weights.begin(), weights.end(), 0);


        int mid=s+(e-s)/2;

        while(s<=e)
        {
            int numsDay=findDays(weights,mid);
            if(numsDay <= days)
            {
                e=mid-1;
            }

            else
            {
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
};