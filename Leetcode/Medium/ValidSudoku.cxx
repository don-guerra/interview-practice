/*
* Problem can be found at: https://leetcode.com/problems/valid-sudoku/
*/

#include <vector>
#include <map>
#include "../ConsoleLogger.hxx"

// Validate a given sudoku
// A valid sudoku table is one that:
// 1. Each row must contain the digits 1-9 without repetition
// 2. Each column must contain the digits 1-9 without repetition
// 3. Each of the nin 3 * 3 sub-boxes of the grid must contain the digits 1-9 without repetition
bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    // Keep a map of when a number has occurred.
    bool rowMap[9][9] = {false};        // Map of 9 rows and 9 possible numbers
    bool columnMap[9][9] = {false};     // Map of 9 columns and 9 possible numbers
    bool gridSquareMap[9][9] = {false}; // Map of 9 grid boxes and 9 possbile numbers

    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[0].size(); col++)
        {
            if (board[row][col] == '.')
                continue;

            int val = (board[row][col]) - '0' - 1;
            int gridSquare = ((row / 3) * 3) + (col / 3);
            if (rowMap[row][val] || columnMap[col][val] || gridSquareMap[gridSquare][val])
            {
                return false;
            }

            rowMap[row][val] = true;
            columnMap[col][val] = true;
            gridSquareMap[gridSquare][val] = true;
        }
    }

    return true;
}

int main()
{
    std::vector<std::vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    printResult("Result", isValidSudoku(board));
}