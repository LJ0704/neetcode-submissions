class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //Brute Force Method: 
        // int j = 0;
        // int k = 0;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(nums[i] == val)
        //     {
        //         k++;
        //         continue;
        //     }

        //     if(i != j)
        //     {
        //         nums[j] = nums[i];
        //     }
        //     j++; 
        // }
        // return j;

        //Two Pointer Method
        int i = 0; 
        if(nums.size() == 0)
        {
            return 0;
        }
        int n = nums.size();
        
        int k = 0;
         while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
            } else {
                i++;
            }
         }
        return n;
    }

};