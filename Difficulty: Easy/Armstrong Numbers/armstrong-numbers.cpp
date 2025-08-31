// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int original = n;
        int sum =0;
        while(n>0)
        {
            int digit = n%10;
            sum = sum + pow(digit,3);
            n=n/10;
            
            
        }
        // cout<< sum << endl;
        // cout<<n<<endl;
            
            if(sum == original)
            {
                return true;
            }
        
            else{
                return false;
            }
        
    }
};