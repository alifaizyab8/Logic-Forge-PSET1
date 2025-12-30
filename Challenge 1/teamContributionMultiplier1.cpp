#include <iostream>
#include <vector>
using namespace std;

vector<int> func(vector<int> &arr)
{
    int multiplier;
    int s = arr.size();
    vector<int> contribution(s);
    for (int i = 0; i < s; i++)
    {
        multiplier = 1;
        for (int j = 0; j < s; j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                multiplier *= arr[j];
            }
        }
        contribution[i] = multiplier;
    }
    return contribution;
}
int main()
{
    vector<int> arr1 = {-1, 1, 0, -3, 3};
    vector<int> arr2 = func(arr1);
    for (int x : arr2)
    {
        cout << " " << x;
    }
}