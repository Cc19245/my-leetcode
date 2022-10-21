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
};