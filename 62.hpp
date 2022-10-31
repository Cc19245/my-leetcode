#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // 1.构造dp数组
        vector<vector<int>> dp(m, vector<int>(n, 0));   

        // 2.初始化dp数组
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        for(int j = 0; j < n; j++)
            dp[0][j] = 1;

        // 3.从上到下、从左到右遍历dp数组
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];  // 递推公式
        
        return dp[m-1][n-1];   // 返回最后结果
    }
};