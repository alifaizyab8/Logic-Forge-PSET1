#include <iostream>
#include <vector>
using namespace std;

// Helper fucntion for stair-case counting
int count(vector<vector<int>> matrix, int target)
{
    int n = matrix.size();
    int row = n - 1;
    int col = 0;
    int count = 0;
    while (row >= 0 && col < n)
    {
        if (matrix[row][col] <= target)
        {
            count += row + 1;
            col++;
        }
        else
        {
            row--;
        }
    }
    return count;
}
int func(vector<vector<int>> matrix, int k)
{
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int counter = count(matrix, mid);
        if (counter < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
        }
    return low;
}
int main()
{
    vector<vector<int>> matrix =
        {
            {1, 5, 9},
            {10, 11, 13},
            {12, 14, 15}};
    int k = 5;
    cout << "Kth smallest is " << func(matrix, k);
}