#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if(nums.size() <= 1)
            return nums.size();
        int result = 0;  // 最终结果

        // 1.定义dp数组
        vector<int> dp(nums.size(), 1);

        // 2.动态规划，计算前面的每一个子串的最长序列
        for(int i = 1; i < nums.size(); i++)
        {
            // 对这个子串，计算它前面的所有子串的最大长度
            for(int j = 0; j < i; j++)
            {
                // 当前位置元素 > 子串的最后一个元素，则递增序列长度可以+1
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);  // 和上一次的比，取最大值
                }
            }
            // 找到了以i结尾的子串的最大递增长度，求最终的最大递增长度
            if(dp[i] > result)
                result = dp[i];
        } 

        return result;
    }
};