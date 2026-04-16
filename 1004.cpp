#include <iostream>
#include <ostream>
#include <vector>

class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int first = 0;
        int last = 0;
        int zeroes = 0;

        int max = 0;
        int length = 0;

        int i = 0; 
        while(last < nums.size())
        {
            if (nums[last] == 0)
            {
                ++zeroes;
            }

            if (zeroes == k)
            {
                length = last - first;
                if (length > max)
                {
                    max = length;
                }

                while(nums[first] != 0)
                {
                    ++first;
                }
            }
            last++;
        }
    }
};