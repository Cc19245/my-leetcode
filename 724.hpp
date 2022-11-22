#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        // 1.统计和
        int sum = 0;
        for(const auto& num : nums)
            sum += num;
        
        int left_sum = 0;
        int right_sum = 0;
        // 2.遍历求左边的和 和 右边的和
        for(int i = 0; i < nums.size(); i++)
        {
            // 注意这个并不是真的left_sum，而是多加了nums[i]
            left_sum += nums[i];  
            // 所以这里right_sum就也要把nums[i]加上
            right_sum = sum - left_sum + nums[i];  
            if(left_sum == right_sum)
                return i;
        }

        // 运行到这里说明没找到，返回-1
        return -1;
    }


    int pivotIndex(vector<int> &nums)
    {   
        // 1.计算总和
        int sum = 0;
        for(const auto& num : nums)
            sum += num;

        int left_sum = 0;   // 左边总和，不包括当前下标
        for(int i = 0; i < nums.size(); i++)
        {
            // 如果此时总和/2等于左边的和
            if(left_sum * 2 == sum - nums[i])   
                return i;
            else 
                left_sum += nums[i];   // 否则累加当前数字，给下一次准备
        }

        // 运行到这里说明没找到，返回-1
        return -1;
    }
};
