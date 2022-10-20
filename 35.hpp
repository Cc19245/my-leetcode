#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 排除三种找不到的情况：空数组，小于最小值，大于最大值
        if(nums.empty())
            return 0;
        if(target < nums[0])
            return 0;
        if(target > nums.back())
            return nums.size();
        
        // 二分查找数组
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(target < nums[middle])
                right = middle - 1;
            else if(target > nums[middle])
                left = middle + 1;
            else
                return middle;
        }

        // 运行到这里，说明没找到，比如[1, 2, 3, 5]中找4，最后找不到。
        // 很明显，最后的结果是[3, 5]中找4，此时left = 2, right = 3; 然后left再右移变成3，left=right=3;
        // 此时target < nums[3], 所以right = middle - 2。此时不满足while循环，退出。
        // 此时可以发现，right = left - 1; 且left的位置就是要插入的位置
        return left;
    }
};