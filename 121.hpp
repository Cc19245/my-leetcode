#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 1.dp数组：dp[i][0]表示第i天不持有股票剩下的钱，dp[i][1]表示持有股票剩下的钱
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0)); 

        // 2.dp数组初始化：第0天不持有股票，剩下的钱就是0；第0天持有股票，剩下的钱是-prices[i]
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        // 3.动态规划：使用状态转移方程递推
        for(int i = 1; i < prices.size(); i++)
        {
            // 不持有股票的剩下的钱：
            // 1.昨天就不持有，则剩下的钱不变；
            // 2.今天卖出，则 剩下的钱 = prices[i] + dp[i-1][1]，即 今天卖出得到的钱+昨天持有股票的剩下的钱
            dp[i][0] = max(dp[i-1][0], prices[i] + dp[i-1][1]);
            
            // 持有股票剩下的钱：
            // 1.昨天就持有股票，则剩下的钱不变，仍然是dp[i-1][1]
            // 2.今天才刚持有股票，则需要花钱今天买入，则剩下的钱是-prices[i]
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }

        // 最终剩下最多的钱，肯定是不持有股票得到的
        return dp[prices.size()-1][0];  
    }
};