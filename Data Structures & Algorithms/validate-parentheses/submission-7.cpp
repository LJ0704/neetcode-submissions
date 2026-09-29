/*
Two pointer Method : Wouldn't work for cases like this s="()[]{}"
Stack Method : 
*/
class Solution {
public:
    bool isValid(string s) {

        /* Two Pointer Method
        // if(s.length() % 2 != 0)
        // {
        //     return false;
        // }
        // int right = s.length() - 1;
        // int left = 0;
        // while(left < right)
        // {
        //     while(s[right] != '{' && s[right] != '}' &&
        //     s[right] != '(' && s[right] != ')' &&
        //     s[right] != '[' && s[right] != ']')
        //     {
        //         right--;
        //     }
        //     while(s[left] != '{' && s[left] != '}' && 
        //           s[left] != '(' && s[left] != ')' && 
        //           s[left] != '[' && s[left] != ']')
        //     {
        //         left++;
        //     }
        //     if(s[right] == ')' && s[left] == '(' ||
        //     s[right] == ']' && s[left] == '[' ||
        //     s[right] == '}' && s[left] == '{'  )
        //     {
        //         right--;
        //         left++;
        //     }
        //     else
        //     {
        //         return false;
        //     }

            
        // }
        // return true;
        */

        /*Method 2 - Using Stack method*/
        stack<char> st;
        char c;
        if(s.length() % 2 != 0)
        {
            return false;
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }

            if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(st.empty())
                {
                    return false;
                }
                c = st.top();
                st.pop();

                if(c == '(' && s[i] != ')')
                {
                    return false;
                }
                else if(c == '[' && s[i] != ']')
                {
                    return false;
                }
                else if(c == '{' && s[i] != '}')
                {
                    return false;
                }
            }

        }

        if(!st.empty())
        {
            return false;
        }
        return true;
    }

};
