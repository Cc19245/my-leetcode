#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        // 从前往后依次计算1,2, ... , i构成的二叉搜索树的数量
        for(int i = 1; i <= n; i++)
        {   
            // 遍历以j为根节点的所有可能
            for(int j = 1; j <=i; j++)
            {
                // 累加j为根节点的时候，构造的二叉搜索树的数量
                dp[i] += dp[j-1] * dp[i-j];  
            }
        }

        return dp[n];   // 返回最终结果
    }
};





