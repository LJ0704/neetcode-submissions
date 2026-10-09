/*
Method 1 : Using hash tables O(nlogn) with sorted strings
Method 2: Using Hash maps with frequency of letters

*/

class Solution {
public:

    string cal_frequency(string str)
    {
        vector<int> freq(26,0);
        string strn;

        for(int i = 0; i < str.length(); i++)
        {
            freq[str[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            strn += to_string(freq[i]) + '#';
        }

        return strn;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, vector<string>> map;
        // vector<vector<string>> res;

        // for(string s : strs)
        // {
        //     string sSorted = s;
        //     sort(sSorted.begin(), sSorted.end());
        //     map[sSorted].push_back(s);
        // }

        // for(auto &x : map)
        // {
        //     res.push_back(move(x.second));
        // }

        // return res;


        //Method 2:

        unordered_map<string, vector<string>> map;
        
        for(int i = 0; i < strs.size(); i++)
        {
            string key = cal_frequency(strs[i]);                       
            map[key].push_back(strs[i]);
                
        }

        vector<vector<string>> res;

        for (auto& entry : map)
        {
            res.push_back(entry.second);
        }


        return res;
        
    }
};
 