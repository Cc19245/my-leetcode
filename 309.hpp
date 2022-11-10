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
        if(prices.empty())
            return 0;
        
        // 1.定义dp数组：0123分别是持有股票、不持有(今天刚卖出)、不持有(今天冷冻期)、不持有(昨天冷冻期，今天无操作)
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));

        // 2.初始化第0天的dp数组
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;

        // 3.动态规划，使用递推公式实现
        for(int i = 1; i < prices.size(); i++)
        {
            // 1.持有股票：昨天就持有股票，或者昨天是冷冻期，今天刚买入，
            //   或者是昨天是冷冻期之后不持有，今天刚买入
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][2], dp[i-1][3]) - prices[i]);

            // 2.不持有(今天刚卖出)：只能是 昨天持有股票，今天卖出
            dp[i][1] = dp[i-1][0] + prices[i];

            // 3.不持有(今天冷冻期)：只能是 昨天为冷冻期之前不持有
            dp[i][2] = dp[i-1][1];

            // 4.不持有(昨天冷冻期，今天无操作)：昨天是冷冻期，或者昨天就是冷冻期之后不持有
            dp[i][3] = max(dp[i-1][2], dp[i-1][3]);
        }

        // 最后返回结果：一定是不持有中的最大值
        return max(dp[prices.size()-1][1], max(dp[prices.size()-1][2], dp[prices.size()-1][3]));
    }
};