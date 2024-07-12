#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int substringLongestLength(const std::string& s) 
{
    std::unordered_map<char, int> index;
    int maxLength = 0, start = 0;

    for (int end = 0; end < s.length(); ++end) 
    {
        if (index.find(s[end]) != index.end()) 
        {
            start = std::max(start, index[s[end]] + 1);
        }
        index[s[end]] = end;
        maxLength = std::max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() 
{
    std::string s;
    std::cout << "Enter the string: ";
    std::getline(std::cin, s);

    int result = substringLongestLength(s);
    std::cout << "The length of the longest substring without repeating characters is: " << result << std::endl;

    return 0;
}
/*
Example:
If the input string is "abcabcbb":

The longest substring without repeating characters is "abc", with a length of 3.
If the input string is "bbbbb":

The longest substring without repeating characters is "b", with a length of 1.
*/