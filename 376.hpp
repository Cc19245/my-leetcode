#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if(nums.size() < 2)
            return nums.size();
        
        // 先找第一个峰值
        int left = 0;
        int pre_diff = 0; // 前一个坡度
        int result = 0;   // 统计的坡度个数

        while(left < nums.size() - 1)
        {
            if(nums[left] != nums[left+1])
            {
                pre_diff = nums[left + 1] - nums[left];
                result = 1;
                break;
            }
            left++;
        }

        // 再找后面的峰值
        while(left < nums.size() - 1)
        {
            int cur_diff = nums[left + 1] - nums[left];
            if((cur_diff > 0 && pre_diff < 0) || (cur_diff < 0 && pre_diff > 0))
            {
                result++;
                pre_diff = cur_diff;
            }
            left++;
        }

        return result + 1;   // 山峰个数 = 坡度个数 + 1
        
    }
};