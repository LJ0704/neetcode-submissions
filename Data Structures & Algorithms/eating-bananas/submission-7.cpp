class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int max_hours = h / size;
        if(h % size)
        {
            max_hours++;
        }

        if(max_hours < 1)
        {
            return -1;
        }

        int max_num = INT_MIN;

        for(int i = 0; i < size; i++)
        {
            max_num = max(max_num, piles[i]);
        }

        int max_speed = max_num;

        if(max_num % max_hours)
        {
            max_speed++;
        }

        int min_speed = 1;
        int mid;
        while(min_speed <= max_speed)
        {
            int hours = 0;
            mid = min_speed + (max_speed - min_speed) / 2;
            
            for(int i = 0; i < size; i++)
            {
                if(piles[i] % mid)
                {
                    hours = hours + (piles[i] / mid) + 1;
                }
                else
                {
                    hours = hours + (piles[i] / mid);
                }                
            }

            if(hours <= h)
            {
                max_speed = mid - 1;
            }else
            {
                min_speed = mid + 1;
            }    
            
        }

        return min_speed;
    }
};
