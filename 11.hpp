#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;

        while(left < right)
        {
            // 计算此次的面积
            int s = min(height[left], height[right]) * (right - left);
            // 和最大面积比较，更新最大面积
            result = max(s, result);
            // 移动短板
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }

        return result;
    }
};