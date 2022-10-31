#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // 1.定义dp数组
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 2.初始化dp数组，注意一旦遇到障碍物，直接不满足for循环，for循环就退出了，然后dp就保持原来的数值0了
        for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
            dp[i][0] = 1;
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
            dp[0][j] = 1;
        
        // 3.从上到下，从左到右遍历每一个位置
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++) 
                // 注意：当前位置是空地才计算路径条数，如果是障碍物，则直接保持原来的dp是0的数值
                if(obstacleGrid[i][j] == 0)   
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};