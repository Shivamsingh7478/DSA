// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        int  i=0;
        int j=1;
        int sum;
        if(n==0 || n==1) return n;
        for(int k=2;k<=n;k++)
        {
            sum = i+j;
            i=j;
            j=sum;
            
            
        }
        
        return sum;
    }
};