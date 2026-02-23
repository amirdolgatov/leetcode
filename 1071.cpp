// For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

// Example 1:

// Input: str1 = "ABCABC", str2 = "ABC"

// Output: "ABC"

// Example 2:

// Input: str1 = "ABABAB", str2 = "ABAB"

// Output: "AB"

// Example 3:

// Input: str1 = "LEET", str2 = "CODE"

// Output: ""

// Example 4:

// Input: str1 = "AAAAAB", str2 = "AAA"

// Output: ""​​​​​​​

// Constraints:

// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of English uppercase letters.

#include <iostream>
#include <string>


class Solution 
{
public:
    std::string_view gcdOfStrings(std::string str1, std::string str2) 
    {
        std::string_view m;
        std::string_view n;

        if (str1.size() > str2.size())
        {
            m = str1;
            n = str2;
        }
        else
        {
            m = str2;
            n = str1;
        }

        while(m.size() != 0 && n.size() != 0)
        {
            // std::cout << "in cycle" << std::endl;
            if (m.size() > n.size())
            {
                //m = m - n;
                if (isBeginningOfLine(m, n))
                {
                    m.remove_prefix(n.size());
                }
                else
                {
                    std::cout << "ret empty" << std::endl;
                    return {};
                }
                // std::cout << "m: " << m << std::endl;
            }
            else
            {
                //n = n - m;
                if (isBeginningOfLine(n, m))
                {
                    n.remove_prefix(m.size());
                }
                else
                {
                    std::cout << "ret empty" << std::endl;
                    return {};
                }
                // std::cout << "n: " << n << std::endl;
            }
        }
        if (n.size() == 0)
        {
            std::cout << "ret: " << m << std::endl;
            return m;
        }
        else
        {
            std::cout << "ret: " << n << std::endl;
            return n;
        }
    }

    bool isBeginningOfLine(std::string_view& str1, std::string_view& str2)
    {
        auto iter_1 = str1.begin();
        auto iter_2 = str2.begin();
        bool ret = false;
        while(*iter_1 == *iter_2 && iter_1 != str1.end() && iter_2 != str2.end())
        {
            iter_1++;
            iter_2++;
        }

        if (iter_2 == str2.end())
        {
            ret = true;
        }
        else if (iter_1 == str1.end())
        {
            ret = false;
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    sol.gcdOfStrings("ABCABC", "ABC");
    sol.gcdOfStrings("ABCABC", "ABCABC");
    sol.gcdOfStrings("ABCABCABC", "ABC");
    sol.gcdOfStrings("ABABABAB", "AB");
    sol.gcdOfStrings("ABAD", "AB");
    sol.gcdOfStrings("ABAD", "ABADABADABAD");
    sol.gcdOfStrings("AAA", "AAAAA");
    sol.gcdOfStrings("AAAVB", "AAAAA");
    sol.gcdOfStrings("AAAXXXXX", "XXXXXAAAAA");
    return 0;
}