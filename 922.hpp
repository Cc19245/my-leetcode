#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0); // 先构造存储结果的数组
        int odd_idx = 1;                    // 初始化奇数和偶数索引
        int even_idx = 0;

        for (const auto &num : nums)
        {
            if (num % 2 == 0) // 偶数
            {
                result[even_idx] = num;
                even_idx += 2;
            }
            else // 奇数
            {
                result[odd_idx] = num;
                odd_idx += 2;
            }
        }

        return result;
    }

    int searchInsert(vector<int> &nums, int target)
    {
        if(nums.empty())
            return 0;
        if(target < nums[0])
            return 0;
        else if(target > nums.back())
            return nums.size();
        else
        {
            int left = 0;
            int right = nums.size();
            // [left ,right)
            while(left < right)
            {
                int middle = left + (right - left) / 2;
                if(target < nums[middle])
                    right = middle;
                else if (target > nums[middle])
                    left = middle + 1;
                else
                    return middle;
            }
            return left;
        }

        return -1;
    }
};