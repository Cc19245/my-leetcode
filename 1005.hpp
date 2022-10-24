/**
 * @file 1005.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-24
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
    static bool compare(int a, int b)
    {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // 1.按照绝对值从大到小排序
        sort(nums.begin(), nums.end(), compare);  
        
        // 2.遍历数组，把其中绝对值大的负数优先翻转
        for(auto& num : nums)
        {
            if(num < 0 && k > 0)
            {
                num *= -1;
                k--;
            }
        }

        // 3.如果翻转后k仍然>0，那么就只反复翻转最后一个数字（整数中最小的），
        //    如果k是奇数，最终结果就是*-1；否则最终结果不变
        if(k % 2 != 0)
            nums.back() *= -1;
        
        // 4.统计翻转后的数组和
        int result = 0;
        for(auto& num : nums)
            result += num;
        
        return result;
    }
};