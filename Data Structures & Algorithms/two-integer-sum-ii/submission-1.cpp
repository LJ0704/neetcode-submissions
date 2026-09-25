/*
Can add one one number in hashmap and check if the diffreence already exists and return the value
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < numbers.size(); i++)
        {
            int num = numbers[i];            
            int diff = target - num;

            if(map.find(diff) != map.end())
            {
                return {map[diff] + 1, i + 1};
            }
            
            map[num] = i;
        }
        return {};
    }
    
};


