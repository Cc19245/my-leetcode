/**
 * @file 35.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * 给定一个有序排列的输入nums和一个目标值target，寻找target按照排序的顺序插入nums的索引
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;


// 暴力解法：依次寻找待插入的位置，时间复杂度n
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 处理三种情况：在数组最开头插入，在中间某个元素的位置插入，在中间两个元素之间的位置插入
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) >= target)
            {
                return i;
            }
        }

        // 处理最后一种情况，在数组的最后插入
        return nums.size();
    }
};


// 二分法查找，先寻找有没有这个元素，然后再处理插入的情况，时间复杂度log(n)
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 使用左闭右闭的二分查找法
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right)
        {
            int middle = left + (right - left)/2;
            if(nums.at(middle) == target)
            {
                return middle;
            }

            if(nums.at(middle) > target)
            {
                right = middle - 1;
            }    
            else
            {
                left = middle + 1;
            }
        }

        // 运行到这里的时候，说明三种情况：
        // 1.target < nums[0], 此时left=0, right=-1
        // 2.target > nums[last], 此时left=nums.size(), right = nums.size()-1
        // 3.target在某两个数之间，假设是nums[a]和nums[a+1]之间，那么遍历到left=a, right=a+1的时候
        //   middle由于是向下取整，所以middle=a，也就是判断nums[a] < target，然后left=a+1。
        //   可以发现此时再次进入循环，因为left=right。然后middle=left=right, 此时判断nums[right]>target
        //   然后right=middle，循环结束。最后left=a+1, right=a，而a+1就是要插入的位置

        // 可以发现，三种情况下，target插入的位置都是left的位置，因此循环到这里的时候，插入的位置就是left
        return left;
    }
};