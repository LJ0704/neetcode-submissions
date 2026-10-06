class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_len = s1.length();
        
        if(s1_len > s2.length())
        {
            return false;
        }
        unordered_map<char, int> map_1;


        for(int i = 0; i < s1_len; i++)
        {
            map_1[s1[i]]++;
        }

        for(int i = 0; i <= (s2.length() - s1_len); i++)
        {
            unordered_map<char, int> map_2;
            
            for(int j = i; j < (i + s1_len); j++)
            {
                map_2[s2[j]]++;
            }

            if(map_1 == map_2)
            {
                return true;
            }
        }

        return false; 

    }
};
