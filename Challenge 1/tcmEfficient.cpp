#include <iostream>
#include <vector>
using namespace std;

vector<int> func(const vector<int> &arr)
{
    int n = arr.size();
    int product = 1;
    vector<int> solution(n);
    // Left Side Product

    for (int i = 0; i < n; i++)
    {
        solution[i] = product;
        product *= arr[i];
    }
    // Right Side Product
    product = 1;
    for (int j = n-1; j >= 0; j--)
    {
        solution[j]*=product;
        product*=arr[j];
    }

    return solution;
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