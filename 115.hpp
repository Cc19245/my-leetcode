#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int numDistinct(string s, string t)
    {
        // 1.定义dp数组
        // 这里dp数组使用long long，因为测试用例中有超过int的
        // 但是提交之后发现还是会报错，最后根据代码随想录上的设置，把这里改成uint64_t才过了
        using ll = long long;   
        vector<vector<ll>> dp(s.size()+1, vector<ll>(t.size()+1, 0));

        // 2.初始化dp数组
        for(int i = 0; i <= s.size(); i++)
            dp[i][0] = 1;   // t是空字符串，则可以在任意的s中出现一次
        for(int j = 1; j <= t.size(); j++)
            dp[0][j] = 0;   // s是空字符串，则t只要不是空，那么t就不可能在s中出现

        // 3.动态规划：开始递推
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= t.size(); j++)
            {
                // 1.如果当前s的字符i == t的字符j，则可以有两种选择（这里为了方便和dp数组对应
                //   直接用i/j了，实际上对应与字符串中的索引是i-1/j-1）：
                //  (1).使用s[i]和t[j]匹配，那么最多出现的次数就是使用s中i-1之前字符和t中j-1
                //    之前字符匹配的个数也就是dp数组中的dp[i-1][j-1]
                //  (2).不使用当前的s[i]和t[j]匹配，而是使用s中i-1之前的字符和t中j之前的字符
                //    匹配的个数，也就是当前的数字虽然匹配上了，但是我不使用它，因为此时是在包括
                //    只使用前面的字符进行匹配的个数，所以此时结果就是dp[i-1][j]，即s中不使用当前的i，
                //    而是用i-1之前的字符匹配t中到j的字符
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                // 2.如果当前s中的字符i != t的字符j，那么结果只能是使用i-1之前的字符串匹配t中
                //   到j的字符串，即dp[i-1][j]
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        // 最后返回结果
        return dp[s.size()][t.size()];
    }
};