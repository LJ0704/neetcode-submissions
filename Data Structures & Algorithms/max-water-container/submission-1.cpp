class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max_area = 0;
        while(left < right)
        {
            int h_min = min(heights[left],heights[right]);
            int l_min = right - left;
            int cal_area = h_min * l_min;
            if(cal_area > max_area)
            {
                max_area = cal_area;
            }

            if(heights[left] >= heights[right])
            {
                right--;
            }else{
                left++;
            }
        }
        return max_area;
    }
};
