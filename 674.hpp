#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if(nums.size() <= 1)
            return nums.size();
        
        int result = 0;  // 最终结果

        // 1.定义并初始化dp数组
        vector<int> dp(nums.size(), 1);

        // 2.动态规划开始递推
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
            {
                dp[i] = dp[i-1] + 1;  // 如果递增，则递增长度+1
            }
            else
            { }// 否则什么也不干，即重新开始一个新的递增序列，递增子序列长度重新初始化成1

            // 记录最终的最长连续递增子序列
            result = dp[i] > result ? dp[i] : result;
        }

        return result;
    }
};