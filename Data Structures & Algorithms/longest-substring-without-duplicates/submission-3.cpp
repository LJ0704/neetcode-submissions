/*
Can it be done using xor + sliding window
if the current count becomes 0 that means an hit is found and current moves to the idx and then continue
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int curr_total = s[0];
        int curr_len = 0;
        int start_idx = 0;
        unordered_map<char, int> map;

        for(int i = 0; i < s.length(); i++)
        {            
            if(map.find(s[i]) == map.end())
            {
                map[s[i]] = i;
               
            }
            else
            {
                start_idx = max(start_idx, map[s[i]] + 1);
                map[s[i]] = i;
            }

            curr_len = i - start_idx + 1; 
            if(curr_len > max_len)
            {
                max_len = curr_len;
            }
        }
        return max_len;
    }
};
