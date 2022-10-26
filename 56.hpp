/**
 * @file 56.hpp
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
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;   // 最终结果

        // 1.如果是空，直接返回结果
        if(intervals.empty())
            return result;
        
        // 2.对区间按照终点进行排序
        sort(intervals.begin(), intervals.end(), compare);

        int left = intervals[0][0];   // 左区间端点
        int right = intervals[0][1];  // 右区间端点

        // 3.遍历所有子区间，寻找不重叠的区间
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= right)  // 当前区间和上一个区间重叠
            {
                left = min(left, intervals[i][0]);
                right = intervals[i][1];   // 更新终点为当前区间终点
            }
            else   // 当前区间和上一个区间不重叠
            {
                vector<int> ans = {left, right};  // 上一个合并的区间
                result.push_back(ans);

                // 更新新的子区间的左右端点
                left = intervals[i][0];   
                right = intervals[i][1];
            }
        }

        // 出了for循环，要把最后一个子区间加到result中
        vector<int> ans = {left, right};  // 上一个合并的区间
        result.push_back(ans);

        return result;
    }
};


class Solution
{
private:
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;   // 最终结果

        // 1.如果是空，直接返回结果
        if(intervals.empty())
            return result;
        
        // 2.对区间按照终点进行排序
        sort(intervals.begin(), intervals.end(), compare);

        int left = intervals[0][0];   // 左区间端点
        int right = intervals[0][1];  // 右区间端点

        // 3.遍历所有子区间，寻找不重叠的区间
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= right)  // 当前区间和上一个区间重叠
            {
                right = max(right, intervals[i][1]);  // 更新右边界
            }
            else   // 当前区间和上一个区间不重叠
            {
                result.push_back({left, right});  // 上一个合并的区间
                // 更新新的子区间的左右端点
                left = intervals[i][0];   
                right = intervals[i][1];
            }
        }

        // 出了for循环，要把最后一个子区间加到result中
        result.push_back({left, right});

        return result;
    }
};