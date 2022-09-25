/**
 * @file 283.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * 给一个数组，把0元素全都移动到数组末尾，其他元素不改变原来的顺序
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
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        // 先把非零元素保存下来
        for(int fast = 0; fast < nums.size(); fast++)
        {
            if(nums[fast] != 0)
            {
                nums[slow++] = nums[fast];
            }
        }

        // 最后把后面的位置全部填充为0
        for(; slow < nums.size(); slow++)
        {
            nums[slow] = 0;
        }
    }
};