// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// Example 1:

// Input: s = "IceCreAm"

// Output: "AceCreIm"

// Explanation:

// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

// Example 2:

// Input: s = "leetcode"

// Output: "leotcede"

#include <iostream>
#include <unistd.h>


class Solution 
{
public:
    std::string reverseVowels(std::string s) 
    {
        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            while(!isVowel(s[left]) && left < right)
            {
                std::cout << "left: " << s[left] << std::endl;
                left++;
            }

            while(!isVowel(s[right]) && left < right)
            {
                std::cout << "right: " << s[right] << std::endl;
                right--;
            }

            if (isVowel(s[left]) && isVowel(s[right]))
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
                std::cout << "change" << std::endl;    
            }

            std::cout << "end iteration" << std::endl;
            sleep(1);
        }

        return s;  
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'i' || c == 'e' || c == 'u' || c == 'y' || c == 'o' ||
        c == 'A' || c == 'I' || c == 'E' || c == 'U' || c == 'Y' || c == 'O'
        ;
    }
};

int main()
{
    Solution solution;
    std::string str = "IceCreAm";
    std::cout << solution.reverseVowels(str) << std::endl;
}