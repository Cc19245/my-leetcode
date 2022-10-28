#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int fib(int n)
    {
        // 0,1 的情况，直接返回结果
        if(n < 2)
            return n;
        vector<int> dp(n+1);  // 注意长度是n+1
        dp[0] = 0;  // dp初始化
        dp[1] = 1;
        // 从前向后遍历
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];  // 递推公式
        }

        return dp[n];
    }
};