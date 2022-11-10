#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if(prices.empty())
            return 0;
        
        // 1.定义dp数组：一天有2*k种状态，表示第k次持有/不持有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2*k, 0));

        // 2.初始化dp数组：0/2/...表示持有，1/3/表示不持有
        for(int j = 0; j < k; j++)
            dp[0][2*j] = -prices[0];

        // 3.动态规划进行递推
        for(int i = 1; i < prices.size(); i++)
        {
            // 第1次持有：昨天就第1次持有，或者昨天第1次不持有，
            // 今天刚买入，就是在昨天不持有的钱 - 今天的价格
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            // 第1次不持有：昨天就第1次不持有，或者今天刚卖出，就是在昨天持有的钱 + 今天的价格
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);

            for(int j = 1; j < k; j++)
            {   
                // 第j次持有：昨天就第j次持有，或者昨天第j-1次不持有，
                // 今天刚买入，就是在昨天第j-1次不持有的钱 - 今天的价格
                dp[i][2*j] = max(dp[i-1][2*j], dp[i-1][2*j-1] - prices[i]);
                
                // 第j次不持有：昨天就第j次不持有，或者昨天第j次持有，
                // 今天刚卖出，就是在昨天持有的钱 + 今天的价格
                dp[i][2*j+1] = max(dp[i-1][2*j+1], dp[i-1][2*j] + prices[i]);
            }
        }

        // 最后，在所有不持有的结果中寻找最大值
        int result = 0;
        for(int j = 0; j < k; j++)
            result = dp[prices.size()-1][2*j+1] > result ? dp[prices.size()-1][2*j+1] : result;
        
        return result;
    }
};