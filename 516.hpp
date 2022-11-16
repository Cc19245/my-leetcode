#pragma once
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        // 1.定义dp数组，并部分初始化
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        // 2.初始化dp数组
        for(int i = 0; i < s.size(); i++)
            dp[i][i] = 1;

        // 3.动态规划：开始递归
        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i + 1; j < s.size(); j++)
            {
                // 1.当前首尾相等，则最长回文序列长度 = 内部子串的最长回文序列长度 + 2(即当前前后两个字符)
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                // 2.否则当前首尾不相等，则要么不要当前字符串的首字符，要么不要尾字符，再去看最长回文序列长度
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][s.size()-1];
    }
};