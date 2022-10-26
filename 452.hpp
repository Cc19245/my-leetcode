/**
 * @file 452.hpp
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
        return a[0] < b[0];   // 按照起点开始排序
    }
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if(points.empty())
            return 0;

        sort(points.begin(), points.end(), compare);
        int result = 1;
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] > points[i-1][1])   // 当前气球开始位置 > 上一个气球结束位置
                result++;
            else  // 当前气球和上一个气球有重复位置
                points[i][1] = min(points[i][1], points[i-1][1]);  // 更新其中终止位置
        }

        return result;
    }
};


