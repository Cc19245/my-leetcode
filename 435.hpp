/**
 * @file 435.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-25
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
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1]; // 按照区间终点开始排序
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // 1.如果是空，则不用移除。这里必须先判断，防止下面sort出错
        if(intervals.empty())
            return 0;   
        // 2.按照区间终点进行排序
        sort(intervals.begin(), intervals.end(), compare);
        int count = 1;   // 最终不重叠的区间个数
        int end = intervals[0][1];   // 上一个区间的尾巴

        for(int i = 1; i < intervals.size(); i++)
        {
            // 如果当前区间的头 >= 上一个区间的尾，则不重叠，保留当前区间
            if(intervals[i][0] >= end)
            {
                end = intervals[i][1];   // 更新当前区间的尾巴为新的尾巴
                count++;  // 累加当前区间，是保留下来的不重叠的区间
            }
        }

        return (intervals.size() - count);  // 总区间 - 保留下的区间 = 要删除的区间
    }
};
