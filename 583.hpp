#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // 1.定义dp数组
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

        // 2.初始化dp数组
        for(int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;
        
        // 3.动态规划：使用递推公式开始递推
        for(int i = 1; i <= word1.size(); i++)
        {
            for(int j = 1; j <= word2.size(); j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1]+2, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }

        // 最后返回结果
        return dp[word1.size()][word2.size()];
    }
};