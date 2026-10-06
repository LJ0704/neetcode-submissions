class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_len = s1.length();

        if(s1_len > s2.length())
        {
            return false;
        }
        unordered_map<char, int> map_1;
        unordered_map<char, int> map_2;


        for(int i = 0; i < s1_len; i++)
        {
            map_1[s1[i]]++;
            map_2[s2[i]]++;
        }

        for(int i = 0; i <= (s2.length() - s1_len); i++)
        {            
            if(map_1 == map_2)
            {
                return true;
            }

            if (i + s1_len < s2.length())
            {
                // Remove character leaving window
                map_2[s2[i]]--;

                if (map_2[s2[i]] == 0)
                {
                    map_2.erase(s2[i]);
                }

                // Add character entering window
                map_2[s2[i + s1_len]]++;
            }

        }

        return false; 

    }
};
