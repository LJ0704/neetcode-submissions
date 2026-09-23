class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == val)
            {
                k++;
                continue;
            }

            if(i != j)
            {
                nums[j] = nums[i];
            }
            j++; 
        }
        return j;
    }

};