#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string func(string log, string pattern)
{
    int right = 0;
    int left = 0;
    int len = log.length();
    int min_len = 100000;
    string result = "";
    unordered_map<char, int> pattern_key;
    for (char c : pattern)
    {
        pattern_key[c]++;
    }
    unordered_map<char, int> substring_key;

    int required = pattern_key.size();
    int matched = 0;

    while (right < len)
    {

        substring_key[log[right]]++;

        if (substring_key[log[right]] == pattern_key[log[right]])
        {
            matched++;
        }

        while (matched == required)
        {

            string substring = log.substr(left, right - left + 1);
            if (substring.length() < min_len)
            {
                min_len = substring.length();
                result = substring;
            }
            if (substring_key[log[left]] == pattern_key[log[left]])
            {

                matched--;
            }
            substring_key[log[left]]--;
            left++;
        }

        right++;
    }
    return result;
}
int main()
{
    string log = "ADOBECODEBANC";
    string passkey = "ABC";
    string substring = func(log,passkey);
    cout<<substring<<endl;
}