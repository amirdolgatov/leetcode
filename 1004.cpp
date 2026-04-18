#include <iostream>
#include <ostream>
#include <vector>

class Solution 
{
public:
    int longestOnes(std::vector<int>& nums, int k) 
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

            while(zeroes > k)
            {
                if (nums[first] == 0)
                {
                    zeroes--;
                }
                first++;
            }
            max = std::max(max, last - first + 1);
        }
        return max;
    }
};

int main()
{                          // 0 1 2 3 4 5 6 7 8 9 101112131415161718
    std::vector<int> nums =  {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    std::vector<int> nums2 = {1,1,1,0,0,0,1,1,1,1,0};
    Solution solution;

    // std::cout << "result = " << solution.longestOnes(nums, 2) << std::endl;
    std::cout << "result = " << solution.longestOnes(nums2, 2) << std::endl;
    std::cout << "result = " << solution.longestOnes(nums, 3) << std::endl;
    // std::cout << "result = " << solution.longestOnes(nums2, 3) << std::endl;
    return 0;
}
