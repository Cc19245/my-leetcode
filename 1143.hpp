#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        if(text1.empty() || text2.empty())
            return 0;
        
        int result = 0;

        // 1.定义dp数组并初始化为0
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));

        // 2.动态规划：使用递推公式开始递推
        for(int i = 0; i < text1.size(); i++)
        {
            for(int j = 0; j < text2.size(); j++)
            {
                if(text1[i] == text2[j])
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