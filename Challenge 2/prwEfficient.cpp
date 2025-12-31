#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool checkContain(unordered_map<char, int> substring_key, unordered_map<char, int> pattern_key)
{
    for (auto &[letter, occurence] : pattern_key)
    {
        if (substring_key[letter] < occurence)
        {
            return false;
        }
    }
    return true;
}
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
    while (right < len)
    {
        substring_key[log[right]]++;
        while (checkContain(substring_key, pattern_key))
        {
            string substring = log.substr(left, right - left + 1);
            if (substring.length() < min_len)
            {
                min_len = substring.length();
                result = substring;
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