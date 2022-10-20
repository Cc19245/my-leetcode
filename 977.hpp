#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        int index = result.size() - 1;   // 从最后一个开始插入

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int left_2 = nums[left] * nums[left];
            int right_2 = nums[right] * nums[right];
            if(left_2 <= right_2)
            {
                result[index--] = right_2;
                right--;
            }
            else
            {
                result[index--] = left_2;
                left++;
            }
        }

        return result;
    }
};