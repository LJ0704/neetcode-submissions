class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right(nums.size(), 1);
        vector<int> left(nums.size(), 1);
        vector<int> multi(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++)
        {
            right[i] = nums[i-1] * right[i-1];
        }

        for(int i = (nums.size() - 2) ; i >=0 ; i--)
        {
            left[i] = nums[i+1] * left[i+1];
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            multi[i] = left[i] * right[i];
        }
        return multi;
    }
};
