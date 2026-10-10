class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int a = 0; 

        for(int i = 0; i < 9; i++)
        {
            int row[9] = {0};
            int column[9] = {0};
            int square[9] = {0};
            for(int j = 0; j < 9; j++)
            { 
                
                int r = 3 * (i / 3) + j / 3;
                int c = 3 * (i % 3) + j % 3;

                // Check row
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';

                    if (row[digit] == 1)
                        return false;

                    row[digit] = 1;
                }

                // Check column
                if (board[j][i] != '.') {
                    int digit = board[j][i] - '1';

                    if (column[digit] == 1)
                        return false;

                    column[digit] = 1;
                }

                // Check 3x3 square
                if (board[r][c] != '.') {
                    int digit = board[r][c] - '1';

                    if (square[digit] == 1)
                        return false;

                    square[digit] = 1;
                }
            }
        }
        
        return true;
    
    
    }
};
