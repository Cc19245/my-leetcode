#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if(s.empty())
            return true;   // 注意这里有点特殊，空字符串是任何字符串的子串

        // 1.定义dp数组并初始化
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

        // 2.动态规划：开始递推
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= t.size(); j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = dp[i][j-1];
            }
        }

        // 最后返回结果：如果dp数组最后一个值等于s.size，则说明s是t的子串
        return dp[s.size()][t.size()] == s.size();
    }
};