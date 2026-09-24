class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;

        for(string s : strs)
        {
            string sSorted = s;
            sort(sSorted.begin(), sSorted.end());
            map[sSorted].push_back(s);
        }

        for(auto &x : map)
        {
            res.push_back(move(x.second));
        }

        return res;
    }
};
 