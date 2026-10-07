class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(); //row
        int columns = matrix[0].size(); //column

        int mid = 0;
        int top = 0;
        int bottom = rows - 1;

        while(top <= bottom)
        {
            mid = (top + bottom) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][columns - 1])
            {
                break;
            }
            else if (target < matrix[mid][0])
            {
                bottom = mid - 1;
            }
            else
            {
                top = mid + 1;
            }
        }

        if (top > bottom)
        {
            return false;
        }

        int start = 0;
        int end = columns - 1;
        rows = mid;
        mid  = 0;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(target == matrix[rows][mid])
            {
                return true;
            }
            else if (target < matrix[rows][mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
};
