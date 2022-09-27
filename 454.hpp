/**
 * @file 454.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-26
 * 
 * 四数相加II
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> record;
        int result = 0;

        // 先求A+B，所有可能的结果存到map中
        for(auto& a : nums1)
        {
            for(auto & b : nums2)
            {
                int num = a + b;
                record[num]++;
            }
        }
        // 再求0-(c+d)，结果如果在A+B的map中，则找到符合条件的元组
        for(auto& c : nums3)
        {
            for(auto& d : nums4)
            {
                if(record.find(-c-d) != record.end())
                {
                    // 注意这里直接 += 是对的，事实是有多个c+d满足要求，
                    // 比如 A+B = 2，C+D=-2，如果有3个A+B=2的组合，有2个C+D=-2的组合
                    // 那么最后元组的个数就是3*2=6，而不是单独的一个3
                    result += record[-c-d];
                }
            }
        }

        return result;
    }
};
