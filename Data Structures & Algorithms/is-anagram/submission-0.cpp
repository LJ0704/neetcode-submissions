class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length())
        {
            return false;
        }

        int arr1[26]=  {0};
        int arr2[26] = {0};

        for(int i = 0; i <= s.length(); i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z'))
            {
                arr1[(s[i] - 'a')]++;
            } 
            if((s[i] >= 'A' && s[i] <= 'Z'))
            {
                arr1[(s[i] - 'A')]++;
            } 
            if((t[i] >= 'a' && t[i] <= 'z'))
            {
                arr2[(t[i] - 'a')]++;
            } 
            if((t[i] >= 'A' && t[i] <= 'Z'))
            {
                arr2[(s[i] - 'A')]++;
            }             
        }

        for(int i =0; i<26 ; i++)
        {
            if(arr1[i] != arr2[i])
            {
                return false;
            }
        }

        return true;

    }
};
