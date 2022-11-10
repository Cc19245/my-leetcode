#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        if(prices.empty())
            return 0;
        
        // 1.定义dp数组：每天要么持有股票，要么不持有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        
        // 2.初始化第1天的dp数组
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        // 3.动态规划：使用dp数组和递推公式
        for(int i = 1; i < prices.size(); i++)
        {
            // 1.持有股票：昨天就持有 或者 昨天不持有，今天刚买入
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);

            // 2.不持有股票：昨天就不持有 或者 昨天持有，今天卖出，注意这里有手续费！
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }

        // 最后返回结果，一定是不持有股票剩余的钱最多
        return dp[prices.size()-1][1];
    }
};