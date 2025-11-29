class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;

        int cnt =0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] > nums[(i+1)%n])
            {
                cnt = cnt+1;

            }
        }

        // if(nums[n-1] > nums[0])
        // {
        //     cnt = cnt+1;
        // }

        return cnt<=1;
    }
}