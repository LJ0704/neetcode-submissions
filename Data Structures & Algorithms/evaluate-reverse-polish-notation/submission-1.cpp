class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int vec_size = tokens.size();
        int val = 0;
        if(vec_size == 1)
        {
            return stoi(tokens[0]);
        }
        for(int i = 0; i < vec_size; i++)
        {
            

            if(tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "+" ||    tokens[i] == "-")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(tokens[i] == "/")
                {
                    val = a / b;
                }
                else if(tokens[i] == "*")
                {
                    val = a * b;
                }
                else if(tokens[i] == "+")
                {
                    val = a + b;
                }
                else
                {
                    val = a - b;
                }
                st.push(val);
                
            }else
            {
                int convert_str = stoi(tokens[i]);
                st.push(convert_str);
            }
        }
        return val;
    }
};
