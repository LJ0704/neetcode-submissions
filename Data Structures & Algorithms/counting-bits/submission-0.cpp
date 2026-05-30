class Solution {
public:
    vector<int> countBits(int n) {
        if(n < 0 || n > 1000)
        {
            return {};
        }
        int inc = 0;

        vector<int> arr(n + 1 ,0);
        for(int i = 0; i <= n; i++)
        {
            int x = i;
            int inc = 0;
            while(x)
            {
                x = x & (x -1);
                inc++;
            }
            arr[i] = inc;
            inc = 0;
        }
        return arr;
    }
};
