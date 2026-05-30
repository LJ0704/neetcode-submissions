class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size_arr = nums.size();
        int total = 0;
        int missing_num = 0;
        for(int i = 0; i < size_arr; i++)
        {
            missing_num = nums[i] ^ missing_num;
            total = total ^ (i + 1) ;
        }
        missing_num = total ^ missing_num;

        return missing_num;
    }
};
