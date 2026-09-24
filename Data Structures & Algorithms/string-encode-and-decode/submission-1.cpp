/*
Method 1 : using Hash Maps 
Method 2 : Can use any encoder like 005 006 for depicting the string lenght
*/
class Solution {
public:

    string encode(vector<string>& strs) {
        //Can convert string to binary string?
        string encoded_string = "";
        for(auto& str : strs)
        {
            for(auto& c : str)
            {
                encoded_string.push_back(c);
            }
            encoded_string.push_back((char)0xFFFFFF);
        }
        return encoded_string;
    }

    vector<string> decode(string s) {

        vector<string> decoded_strs;

        string str = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == (char)0xFFFFFF)
            {
                decoded_strs.push_back(str);
                str = "";
            }
            else
            {
                str.push_back(s[i]);
            }
        }
        return decoded_strs;
    }
};
