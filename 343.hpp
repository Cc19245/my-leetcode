#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n+1);   // 从0开始，主要是为了数组索引的对应
        dp[2] = 1;   // 1+1 = 2, 1x1 = 1
        
        // 从前往后遍历每一个数字，寻找其拆分的乘积最大值
        for(int i = 3; i <=n; i++)
        {
            int max_prod = 0;   // 当前位置i的数字，拆分的乘积最大值，在for循环过程中会不断变化
            // 对当前的数字i，把它拆成j+(i-j)，然后(i-j)还可以继续拆分
            for(int j = 1; j <= i-2; j++)
            {
                int this_prod = max(j*(i-j), j*dp[i-j]);   // 拆分成2个数字和2个以上数字的乘积最大值
                if(this_prod > max_prod)   // 更新乘积最大值
                    max_prod = this_prod;    
            }
            dp[i] = max_prod;   // 最后找出来了拆分的乘积最大值，赋值给dp[i]
        }

        return dp[n];   // 最后返回n的乘积最大值
    }
};