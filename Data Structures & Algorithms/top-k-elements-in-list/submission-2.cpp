class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int i = 0; i< nums.size(); i++)
        {
            map[nums[i]]++;
        }

         // Find the k most frequent
        for(int j = 0; j < k; j++)
        {
            int maxFreq = 0;
            int maxNum = 0;

            for(auto& pair : map)
            {
                if(pair.second > maxFreq)
                {
                    maxFreq = pair.second;
                    maxNum = pair.first;
                }
            }

            res.push_back(maxNum);

            // Remove it so we don't select it again
            map.erase(maxNum);
        }
        return res;
    }
};
