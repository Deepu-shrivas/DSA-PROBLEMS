class Solution {
public:

    // Check whether num can be placed at board[row][col]
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {

        // 1. Check the row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;
        }

        // 2. Check the column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num)
                return false;
        }

        // 3. Find the starting position of 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        // Check the 3x3 box
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    // Backtracking function
    bool solve(vector<vector<char>>& board) {

        // Visit every cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                // Find an empty cell
                if (board[row][col] == '.') {

                    // Try numbers  from 1 to  9
                    for (char num = '1'; num <= '9'; num++) {

                        // Check if number is valid then return 
                        if (isValid(board, row, col, num)) {

                            // Place the number 
                            board[row][col] = num;

                            // Recursively solve
                            if (solve(board))
                                return true;

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    // No number works
                    return false;
                }
            }
        }

        // No empty cells → Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};