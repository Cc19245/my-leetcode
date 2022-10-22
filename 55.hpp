#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if(nums.size() == 1)
            return true;
        
        int cover = 0;
        for(int i = 0; i <= cover; i++)
        {
            // 跟新新的最大范围
            cover = cover < (i + nums[i]) ? (i + nums[i]) : cover;
            if(cover >= nums.size() - 1)  // 一旦可以达到最大范围，直接return
                return true;
        }   

        return false;
    }

    bool canJump(vector<int> &nums)
    {
        if(nums.size() == 1)   // 只有一个数，不用跳就在终点，所以是true
            return true;
        
        int this_cover = nums[0];  // 当前遍历的最大范围
        int next_cover = 0;   // 从当前遍历的范围中计算下一次遍历的最大范围
        
        if(this_cover >= nums.size() - 1)  // 第一步就能跳到最终位置
            return true;
        
        // 运行到这里说明第一步调不到终点，还要多跳几步
        int i = 0;
        for(; i <= this_cover; i++)    // 遍历当前的范围，寻找下一次的最大范围
        {
            next_cover = max(next_cover, i + nums[i]);
            if(i == this_cover)   // 遍历到当前最后一个位置了
            {
                this_cover = next_cover;   // 更新下一次遍历的最大范围
                if(this_cover >= nums.size() - 1)  // 一旦可以达到最大范围，直接return
                    return true;
            }     
        }   

        // 运行到这里，说明无法跳到终点
        return false;
    }

};
