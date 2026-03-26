#include <iostream>
#include <ostream>
#include <vector>

class Solution 
{
public:
    int maxOperations(std::vector<int>& nums, int k) 
    {

        quickSort(nums, 0, nums.size() - 1);

        int i = 0;
        int j = nums.size() - 1;
        int count = 0;

        while(i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                count++;
                i++;
                j--;
            }
            else if (nums[i] + nums[j] < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return count;
    }

    void quickSort(std::vector<int>& nums, int l, int r)
    {
        if (l >= r)
        {
            return;
        }

        int v = nums[(l + r)/2];
        int i = l;
        int j = r;

        while(i <= j)
        {
            while(nums[i] < v)
            {
                i++;
            }
            while(nums[j] > v)
            {
                j--;
            }
            if (i <= j)
            {
                std::swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        quickSort(nums, l, j);
        quickSort(nums, i, r);
    }
};

void print(std::vector<int>& nums)
{
    for (auto num: nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;
    std::vector<int> nums = {1,2,3,4};

    solution.quickSort(nums, 0, nums.size() - 1);
    print(nums);
} 