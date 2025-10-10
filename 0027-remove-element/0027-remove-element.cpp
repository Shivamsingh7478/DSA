class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int i=0;

        // int j = nums.size() -1;
        // while(i<j)
        // {
        //     if(nums[i]==val && nums[j]==val)
        //     {
        //        j--;
        //     }

        //     else if(nums[i] != val && nums[j] == val)
        //     {
        //         i++;
        //     }

        //     else if(nums[i] == val && nums[j] != val)
        //     {
        //         swap(nums[i], nums[j]);
        //         i++;
        //         j--;
        //     }
        // }

        // int count = 0;

        // for(int i=0;i<nums.size() ;i++)
        // {
        //     if(nums[i] != val)
        //     {
        //         count++;
        //     }
        //     else{
        //         return count;
        //     }
        // }

        // return count;


        int index =0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != val)
            {
                nums[index] = nums[i];
                 index++;
            }

           
        }


        return index;
    }
};