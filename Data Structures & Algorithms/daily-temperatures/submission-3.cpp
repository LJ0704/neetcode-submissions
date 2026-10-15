/*
    Brute Force Method : O(n^2)
    Stack Method : Add elements from backwards

*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int vec_size = temperatures.size() - 1;
        stack<int> st;

        vector<int> output_vec(temperatures.size(), 0);
        for(int i = vec_size; i >= 0; i--)
        {
            if(i == vec_size)
            {
                output_vec[i] = 0;
                st.push(i);
                continue;
            }

            while(!st.empty())
            {
                int index = st.top();
                if(temperatures[i] < temperatures[index])
                {
                    output_vec[i] = index - i;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            
            st.push(i);
        }
        return output_vec;
    }
};
