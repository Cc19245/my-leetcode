#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int pre = 0;
        int cur = 1;
        int sum = 0;
        while (cur < prices.size())
        {
            int diff = prices[cur++] - prices[pre++];
            if (diff > 0)
                sum += diff;
        }

        return sum;
    }

    int maxProfit(vector<int> &prices)
    {
        // 1.定义dp数组：dp[i][0]第i天不持有股票最多剩余的钱；dp[i][1]第i天持有股票最多剩余的钱
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        
        // 2.初始化dp数组
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        // 3.动态规划：利用递推公式开始递推
        for(int i = 1; i < prices.size(); i++)
        {
            // 今天不持有股票剩余的最多的钱：1.昨天就不持有； 2.昨天持有，今天卖出
            dp[i][0] = max(dp[i-1][0], prices[i] + dp[i-1][1]);

            // 今天持有股票剩余最多的钱：1.昨天就持有；2.今天刚买入：昨天不持有的钱 - 今天购入花的钱
            // 注意：这个地方由于可以多次买卖股票，所以昨天不持有股票剩余的钱未必是0，而是dp[i-1][0]
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        // 4.最后剩余最多的钱，一定是最后一天不持有股票剩余的钱
        return dp[prices.size()-1][0];
    }
};