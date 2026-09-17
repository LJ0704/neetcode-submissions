class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while(left <= right)
        {
            int i = left + (right - left) / 2;
            if(nums[i] == target)
            {
                return i;
            }
            else if(target < nums[i])
            {
                right = i - 1;
            }
            else
            {
                left = i + 1;
            }
        }
        return -1;
    }
};
