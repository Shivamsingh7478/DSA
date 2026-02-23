class Solution {
    static int febRec(int n, int[] memo)
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }

        if(memo[n] != -1)
        {
            return memo[n];
        }

        memo[n] = febRec(n-1, memo) + febRec(n-2, memo);
        return memo[n];
    }

    static int solveTabulation(int n)
    {
        int[] memo = new int[n+1];

        memo[0] = 0;
        if(n==0)
        {
            return 0;
        }
        memo[1] = 1;

        for(int i=2;i<= n;i++)
        {
            memo[i] = memo[i-1]+memo[i-2];

        }

        return memo[n];
    }
    public int fib(int n) {
        // int[] memo = new int[n+1];
        // Arrays.fill(memo, -1);
        // return febRec(n, memo);

        return solveTabulation(n);
    }
}