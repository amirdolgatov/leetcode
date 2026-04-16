#include <iostream>
#include <ostream>
#include <vector>

class Solution 
{
public:
    int maxVowels(string s, int k) 
    {
        if (s.size() == 0 || k == 0)
        {
            return 0;
        }

        int begin = 0;
        int end = k;
        int max = 0;
        int current = 0;

        while (end < s.size())
        {
            current = vowelsInRange(s, begin, end);
            if (current > max)
            {
                max = current;
            }

            ++begin;
            ++end;
        }
        return max;
    }

    int vowelsInRange(string &s, int begin, int end)
    {
        int count = 0;
        for (int i = begin; i < end; i++)
        {
            if (isVowel(s[i]))
            {
                ++count;
            }
        }
        return count;
    }

    bool isVowel(char c)
    {
        return ((c == 'a') || (c == 'u') || (c == 'e') || (c == 'i') || (c == 'o'));
    }
};