#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if(nums.empty())
            return 0;
    
        // 1.定义dp数组
        vector<int> dp(nums.size(), 0);

        // 2.dp数组初始化
        dp[0] = nums[0];
        int result = dp[0];

        // 3.动态规划：开始递推
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            result = dp[i] > result ? dp[i] : result;
        }

        return result;
    }
};