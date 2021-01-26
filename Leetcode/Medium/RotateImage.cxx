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
    // Rotating array in place
    // For each element we have a total of four positions we need to rotate
    // 5    1   9   11      (0, 0)    (0, 1)    (0, 2)    (0, 3)
    // 2    4   8   10      (1, 0)    (1, 1)    (1, 2)    (1, 3)
    // 13   3   6   7       (2, 0)    (2, 1)    (2, 2)    (2, 3)
    // 15   14  12  16      (3, 0)    (3, 1)    (3, 2)    (3, 3)
    //
    // We would need to swap 10 with 1, swap 10 with 14, swap 14 with 2 and finally swap 2 with 1
    // There is a mapping between these positions when we rotate (row, col) -> (col, size - 1 - row)
    // Yet we can make the four rotations at the once to simplify how we don't lose values during rotation
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