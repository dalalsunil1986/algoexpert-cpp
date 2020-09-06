#include <algorithm>
#include <string>

bool isPalindrome(std::string str)
{
    std::size_t size = str.size();
    for (int i = 0; i < size / 2; i++)
    {
        if (str[i] != str[size - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool isPalindrome2(std::string str)
{
    std::string reversedStr{str};
    std::reverse(reversedStr.begin(), reversedStr.end());

    return reversedStr == str;
}