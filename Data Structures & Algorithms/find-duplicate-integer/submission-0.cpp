/*
Method 1 : use hashmaps and check the count of the number -> frequency
Method 2 : sort and match
Method 3 : Best method is to do Floyds algorithm
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        //when they meet move slow to start and then keep going in circles again
        //Distance from the start == distance from the loop, not sure how is it true
        
        slow = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
