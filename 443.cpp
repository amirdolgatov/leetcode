#include<iostream>
#include<string>
#include<vector>

class Solution 
{
public:
    int compress(std::vector<char>& chars) 
    {
        // start
        if (chars.size() == 0)
        {
            return 0;
        }

        if (chars.size() == 1)
        {
            return 1;
        }
        
        int i = 0;
        int j = 0;
        int count = 0;
        char prev = chars[i++];
        chars[j++] = prev;
        count++;

        char s[100];

        while(i < chars.size())
        {
            if (i + 1 == chars.size())
            {
                if (chars[i] == prev)
                {
                    count++;
                    int len = int_to_char(count, s);
                    for(int k = 0; k < len; k++)
                    {
                        chars[j++] = s[k];
                    }
                }
                else
                {
                    if(count > 1)
                    {
                        int len = int_to_char(count, s);
                        for(int k = 0; k < len; k++)
                        {
                            chars[j++] = s[k];
                        }
                    }
                    chars[j++] = chars[i];
                }
                break;
            }

            if(chars[i] == prev)
            {
                count++;
            }
            else
            {
                if (count > 1)
                {
                    int len = int_to_char(count, s);
                    for(int k = 0; k < len; k++)
                    {
                        chars[j++] = s[k];
                    }
                }
                chars[j++] = chars[i];
                prev = chars[i];
                count = 1;
            }
            i++;
        }
        chars.resize(j);
        return j; 
    }

    int int_to_char(int num, char * buffer)
    {
        int len = 0;

        do
        {
            buffer[len++] = '0' + num % 10;
        }
        while((num /= 10) > 0);

        reverseStr(buffer, len);
        return len;
    }

    void reverseStr(char * str, int len)
    {
        for (int i = 0; i < len/2; ++i)
        {
            char temp = str[i];           
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
    }
};

int main ()
{
    char abc[100] = {0};
    Solution solution;
    std::vector<char> chars = {'a','a','a','d'};
    solution.compress(chars);

    for(auto c: chars)
    {
        printf("%c ", c);
    }
    return 0;
}