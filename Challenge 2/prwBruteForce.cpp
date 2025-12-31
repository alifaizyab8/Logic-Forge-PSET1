#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


// Helper dictionary comparison function
bool checkContain(unordered_map<char,int> substring_key, unordered_map<char,int> pattern_key)
{
    for(auto &[letter,occurence] : pattern_key)
    {
        if (substring_key[letter]<occurence)
        {
            return false;
        }
        

    }
    return true;
}
string func(string log, string pattern)
{
    int len = log.length();
    unordered_map<char, int> pattern_key;
    for (char c : pattern)
    {
        pattern_key[c]++;
    }
    // Checking all possible substrings
    int min_len = 100000;
    string result = "";
    for (int initial = 0; initial < len; initial++)
    {
        for (int final = initial; final < len; final++)
        {
            string substring = log.substr(initial, final - initial + 1);
            unordered_map<char, int> substring_key;
            for (char c : substring)
            {
                substring_key[c]++;
            }
            if (checkContain(substring_key,pattern_key))
            {
                if (substring.length()<min_len)
                {
                    min_len = substring.length();
                    result = substring;
                }
                
            }
            
        }
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