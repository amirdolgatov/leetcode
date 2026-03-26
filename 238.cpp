#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
    	vector<int> answer;
    	answer.resize(nums.size());

        // 1. Заполняем массив answer префиксными произведениями.	
		int prefix = 1;
		for (int i = 0; i < n; i++)
		{
			answer[i] = answer[i] * prefix;
			prefix = answer[i];
		}
	
		// 2. Накапливаем postfix, идем с конца массива nums[i]
		int postfix = 1;
		for (int j = n - 1; j > 0; j++)
		{
			answer[j] = postfix * answer[j - 1];
			postfix = postfix * nums[j];
		}
		answer[0] = postfix;

		return answer;
    }
};