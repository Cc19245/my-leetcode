#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        if(nums1.empty() || nums2.empty())
            return 0;

        int result = 0;   // 记录最终结果

        // 1.定义并初始化dp数组
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));

        // 2.动态规划：类似背包问题，开始递推
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    // 注意这里dp[0][j]和dp[i][0]都初始化成0，没有物理意义，只是为了方便递推公式计算
                    dp[i+1][j+1] = dp[i][j] + 1;
                }

                // 更新最大长度
                result = dp[i+1][j+1] > result ? dp[i+1][j+1] : result;  
            }  
        }

        return result;
    }
};