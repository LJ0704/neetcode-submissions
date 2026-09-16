class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
    /*Assume that every input has exactly one pair of indices i and j 
    that satisfy the condition*/
    //nums[i] + nums[j] == target, i != j 
    unordered_map<int, int> hash_table;
    for(int i = 0; i < nums.size(); i++)
    {
        int differ = target - nums[i];
        if(hash_table.find(differ) != hash_table.end())
        {
            return {hash_table[differ],i};
        }else{            
            hash_table.insert({nums[i], i});
        }
    }
    return {};
    }
};
