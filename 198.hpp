/**
 * @file 198.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 1.一些特殊情况，可以直接判断出结果
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];

        // 2.运行到这里，说明nums中至少有两个数，则建立dp数组并初始化
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // 3.遍历dp数组，使用递推公式填满dp数组
        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        // 4.最后一个位置就是考虑所有的房间，得到的最大的打劫价值
        return dp.back();
    }
};