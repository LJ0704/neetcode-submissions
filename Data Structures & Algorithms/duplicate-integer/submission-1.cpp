// Method 1:
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         int j = 0;
//         int dup = 0;
//             for(int i = 0; i < nums.size() ; i++)
//             {
//                 for(int j = i; j < nums.size(); j++)
//                 {
//                     if(nums[i] == nums[j] && i != j)
//                     {
//                         return true;
//                     }
//                 }
//             }
//             return false;
//     }
// };

//Method 2: Sorting Need to look into
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {    
//     }
// };

//Method 3: Hash Maps 
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
            if(map[nums[i]] > 1)
            {
                return true;
            }
        }
        return false;
    
    }
};