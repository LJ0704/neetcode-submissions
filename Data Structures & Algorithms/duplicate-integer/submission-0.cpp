class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int j = 0;
        int dup = 0;
            for(int i = 0; i < nums.size() ; i++)
            {
                for(int j = i; j < nums.size(); j++)
                {
                    if(nums[i] == nums[j] && i != j)
                    {
                        return true;
                    }
                }
            }
            return false;
    }
};