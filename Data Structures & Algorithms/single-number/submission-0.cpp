class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        int size_arr = nums.size();
        for(int i = 0; i < size_arr; i++)
        {
            n = nums[i] ^ n;            
        }
        return n;
    }
};
