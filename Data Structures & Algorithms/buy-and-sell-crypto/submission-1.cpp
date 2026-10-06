/*
Method 1 : Find the minimum value and its index and find the max after that value 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0;
        int max_total = INT_MIN;
        int max_total_idx = 0;
        int curr_total = INT_MIN;
        int curr_total_idx = 0; 
        int current = INT_MAX;
        int curr_idx = 0;
        int min_idx = 0;
        for(int k = 0; k < prices.size(); k++)
        {
            if(prices[k] < current)
            {
                current = prices[k];
                curr_idx = k;
            }
               
            curr_total = prices[k] - current;
            

            if(max_total < curr_total)
            {
                min_idx = curr_idx;
                max_total = curr_total;
                max_total_idx = k;
            }

        }
        return (max_total);
        
    }
};
