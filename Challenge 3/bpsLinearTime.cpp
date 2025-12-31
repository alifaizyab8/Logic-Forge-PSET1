#include <iostream>
#include <vector>
using namespace std;

double func(vector<int> &arr1, vector<int> &arr2)
{
    int len1 = arr1.size();
    int len2 = arr2.size();
    int total_len = len1 + len2;
    // Calculating required indicies
    int req_index_1;
    int req_index_2;
    bool even = ((total_len) % 2) == 0;
    if (even)
    {
        req_index_1 = total_len / 2 - 1;
        req_index_2 = total_len / 2;
    }
    else
    {
        req_index_1 = req_index_2 = total_len / 2;
    }
    int i = 0, j = 0, traversed = 0;
    int val1, val2;
    while (traversed <= req_index_2)
    {
        int present_val;
        if (i < len1 && j < len2)
        {
            if (arr1[i] < arr2[j])
            {
                present_val = arr1[i];
                i++;
            }
            else
            {
                present_val = arr2[j];
                j++;
            }
        }
        else if (i < len1)
        {
            present_val = arr1[i];
            i++;
        }
        else
        {
            present_val = arr2[j];
            j++;
        }
        if (traversed == req_index_1)
        {
            val1 = present_val;
        }
        if (traversed == req_index_2)
        {
            val2 = present_val;
        }
        traversed++;
    }
    if (even)
    {
        return (val1 + val2) / 2.0;
    }
    else
    {
        return val2;
    }
}
int main()
{
    vector<int> scoreA = {1, 2};
    vector<int> scoreB = {3, 4};
    double answer = func(scoreA, scoreB);
    cout << answer;
}