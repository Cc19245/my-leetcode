#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.empty() || nums1.empty())
            return 0;
        
        int result = 0;

        // 1.定义dp数组并初始化为0
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));

        // 2.动态规划：使用递推公式开始递推
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
                result = dp[i+1][j+1] > result ? dp[i+1][j+1] : result;
            }
        }

        return result;
    }
};