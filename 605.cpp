// 605. Can Place Flowers

// Easy
// Topics
// premium lock icon
// Companies
// You have a long flowerbed in which some of the plots are planted, and some are not. 
// However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, 
// where 0 means empty and 1 means not empty, and an integer n, 
// return true if n new flowers can be planted in the flowerbed 
// without violating the no-adjacent-flowers rule and false otherwise.

// Example 1:

// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true
// Example 2:

// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: false
 
#include <iostream>
#include <vector>

class Solution 
{
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) 
    {
    	int index = 0; 
		int end = flowerbed.size();
		while(index < end)								// первый проход
		{
			if (flowerbed[index] == 1)
			{
				if (index != 0)
				{
					flowerbed[index - 1] = 1;
				}
				if (index != end - 1)
				{
					flowerbed[index + 1] = 1;
				}
				index = index + 2;
				continue;
			}
			++index;
		}

		index = 0;
		int empty = 0;
		while(index < end)							// второй проход, размещаем цветы
		{
			if (flowerbed[index] == 0)
			{
				if (index != 0)
				{
					flowerbed[index - 1] = 1;
				}
				if (index != end - 1)
				{
					flowerbed[index + 1] = 1;
				}

				flowerbed[index] = 1;
				index = index + 2;
				++empty;
				continue;
			} 
			++index;
		}
		return empty >= n;
    }
};

int main()
{
	std::vector flowerbed = {1,0,0,0,1,0,0,0};
	Solution solution;
	std::cout << "answer: " << solution.canPlaceFlowers(flowerbed, 2) << std::endl;
}