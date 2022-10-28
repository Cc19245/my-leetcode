#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        // 1层楼，就是1步；2层楼就是2步
        if(n < 3)
            return n;

        vector<int> dp(n+1);
        dp[1] = 1;  // dp数组初始化
        dp[2] = 2;
        // 从前向后遍历
        for(int i = 3; i <=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];  // 递推公式
        }
        
        return dp[n];
    }
};