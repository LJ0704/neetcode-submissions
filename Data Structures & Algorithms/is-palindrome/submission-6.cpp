class Solution {
public:
    bool isPalindrome(string s) {
        char* start = s.data();
        char* end = s.data() + s.length() - 1;
        while(end > start)
        {
            while((start < end) && ((*start < '0' || *start > '9') && (*start < 'a' || *start > 'z') && ((*start < 'A' || *start > 'Z'))))
            {
                start++;
            }
             while((start < end) && ((*end < '0' || *end > '9') && (*end < 'a' || *end > 'z') && ((*end < 'A' || *end > 'Z'))))
            {
                end--;
            }
            
            if(*start >= 'a' && *start <= 'z')
            {
                *start = *start - 32;
            }
            if(*end >= 'a' && *end <= 'z')
            {
                *end = *end - 32;
            }
            if(*start == *end)
            {
                start++;
                end --;
            }
            else
            {
                return false;
            } 
        }

        return true;

    }
};
