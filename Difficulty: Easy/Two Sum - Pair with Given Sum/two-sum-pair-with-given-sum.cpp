class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        int l=0;
        int h = arr.size()-1;
        while(l<h){
        int csum = arr[l]+arr[h];
        if(csum == target)
        {
            return true;
        }
        else if(csum > target)
        {
            h--;
        }
        else
        {
            l++;
        }
        }
        return false;
    }
};