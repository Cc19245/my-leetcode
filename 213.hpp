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
private:
    // [start, end]
    int robRange(vector<int> &nums, int start, int end)
    {
        // 1.只有一个元素，直接返回元素值
        if(start == end)
            return nums[start];
      
        // 2.运行到这里，说明nums中至少有两个数，则建立dp数组并初始化
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);

        // 3.遍历dp数组，使用递推公式填满dp数组
        for(int i = start+2; i <= end; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        // 4.最后一个位置就是考虑所有的房间，得到的最大的打劫价值
        return dp[end];
    }
    
public:
    int rob(vector<int>& nums)
    {
        // 1.判断特殊条件，直接返回结果
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        // 2.开始分两种情况打劫
        int res1 = robRange(nums, 0, nums.size()-2);
        int res2 = robRange(nums, 1, nums.size()-1);
        
        // 3.返回结果
        return max(res1, res2);
    }
};