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

        // 1.定义dp数组：行数为股票价格天数，列数为4，分别表示
        // 第1次持有股票、第1次不持有股票、第2次持有股票、第2次不持有股票的最多剩余的钱
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));  

        // 2.dp数组初始化
        dp[0][0] = -prices[0];   // 第一次持有：-prices[0]
        dp[0][1] = 0;            // 第一次不持有：0
        dp[0][2] = -prices[0];   // 第二次持有：-prices[0]
        dp[0][3] = 0;            // 第二次不持有：0

        // 3.动态规划：递推
        for(int i = 1; i < prices.size(); i++)
        {
            // 第一次持有：昨天就第一次持有，或者 今天才第一次持有，
            // 即今天第一次买入（结果就是-prices[i]，因为之前剩余的钱就是0）
            dp[i][0] = max(dp[i-1][0], -prices[i]);

            // 第一次不持有：昨天就第一次不持有，或者 今天才第一次不持有，
            // 即今天第一次卖出（结果是昨天第一次持有剩余的钱 + 今天卖出收获的钱）
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            
            // 第二次持有：昨天就第二次持有，或者 今天才第二次持有，
            // 即今天第二次买入（结果就是dp[i-1][1]-prices[i]，因为之前剩余的钱就是昨天第一次不持有）
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i]);

            // 第二次不持有：昨天就第二次不持有，或者 今天才第二次不持有，
            // 即今天第二次卖出（结果就是昨天第二次持有剩余的钱 + 今天卖出收获的钱）
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i]);
        }

        // 最后返回结果：肯定是不持有股票剩余的钱最多
        return max(dp[prices.size()-1][1], dp[prices.size()-1][3]);
    }
};