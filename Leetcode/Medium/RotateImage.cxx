/*
* Link to problem: https://leetcode.com/problems/rotate-image/
*/

#include <vector>
#include "../ConsoleLogger.hxx"

void rotate(std::vector<std::vector<int>> &matrix)
{
    // Transpose by swapping x and y position
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = row + 1; col < matrix[0].size(); col++)
        {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }

    // Reverse the 2D array
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[0].size() / 2; col++)
        {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[row][matrix.size() - col - 1];
            matrix[row][matrix.size() - col - 1] = temp;
        }
    }
}

void rotateSimp(std::vector<std::vector<int>> &matrix)
{
    for (int row = 0; row < matrix.size() / 2; row++)
    {
        for (int col = row; col < matrix[0].size() - row - 1; col++)
        {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[matrix.size() - 1 - col][row];
            matrix[matrix.size() - 1 - col][row] = matrix[matrix.size() - 1 - row][matrix.size() - 1 - col];
            matrix[matrix.size() - 1 - row][matrix.size() - 1 - col] = matrix[col][matrix.size() - 1 - row];
            matrix[col][matrix.size() - 1 - row] = temp;
        }
    }
}

void rotateN(std::vector<std::vector<int>> &matrix, int rotations)
{
    while (rotations-- > 0)
    {
        rotateSimp(matrix);
    }
}

int main()
{
    std::vector<std::vector<int>> matrix{
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};

    print2D("Initial", matrix);
    rotateN(matrix, 1);
    print2D("After", matrix);

    return 0;
}