#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int func(vector<vector<int>> &matrix, int k)
{

    int result = 0, row = 0, col = 0;
    int n = matrix.size();

    // Type vector<int> to store as following {value, row, col}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

    // Adding the first element of each row
    for (int i = 0; i < n; i++)
    {
        minHeap.push({matrix[i][0], i, 0});
    }
    for (int i = 0; i < k; i++)
    {
        vector<int> smallest = minHeap.top();
        minHeap.pop();
        result = smallest[0];
        row = smallest[1];
        col = smallest[2];

        if (col + 1 < n)
        {
            minHeap.push({matrix[row][col + 1], row, col + 1});
        }
    }
    return result;
}
int main()
{
    vector<vector<int>> matrix =
        {
            {1, 5, 9},
            {10, 11, 13},
            {12, 14, 15}};
    int k = 4;
    cout << "Kth smallest is " << func(matrix, k);
}