/**
 * @file 26.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * 给一个升序排列的数组，删除它里面的重复元素，并把最终的元素全放到数组前面，然后返回数组的长度
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slow = 0;
        int already_num = INT32_MAX;   // 已有的数，先备份成一个不在题目范围内的数

        for(int fast = 0; fast < nums.size(); fast++)
        {
            // 双指针，如果还没有这个数，那么才存到新的数组中
            if(nums[fast] != already_num)
            {
                already_num = nums[fast];
                nums[slow++] = already_num;
            }
        }
        return slow;
    }
};