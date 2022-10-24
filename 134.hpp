/**
 * @file 134.hpp
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
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int cur_sum = 0;    // [上一个起始位置，当前位置]的剩余油量
        int total_sum = 0;  // 遍历完所有加油站，剩余油量
        int start = 0;   // 最终计算的起始位置

        for(int i = 0; i < gas.size(); i++)
        {
            cur_sum += gas[i] - cost[i];    // 统计 [上一个起始位置，当前位置]的剩余油量
            total_sum += gas[i] - cost[i];  // 统计 遍历完所有加油站，剩余油量
            // 一旦[上一个起始位置，当前位置]的剩余油量是负数，那么就要更新起始位置，重新统计剩余油量
            if(cur_sum < 0)
            {
                start = i + 1;
                cur_sum = 0;  // 清零，重新统计[新的起始位置，当前位置]的剩余油量
            }
        }

        if(total_sum < 0)  // 如果总剩余油量<0，肯定无法跑完全程
            return -1;
        
        // 运行到这里，总剩余油量>0，则我们计算的start就是起始位置
        return start;
    }
};