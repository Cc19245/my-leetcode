#pragma once
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


class Solution
{
public:
    int countSubstrings(string s)
    {
        // 1.定义dp数组并初始化
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        int result = 0;   // 最终结果

        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                // 1.如果当前起始字符和结束字符不相等，那么肯定就不是回文了
                if(s[i] != s[j])   
                    dp[i][j] = false;
                else
                {
                    // 2.否则如果相等，则判断字符长度：
                    //  2.1.如果是1或2，比如a或aa的情况，自然是回文
                    if(j - i <= 1)
                    {
                        result++;   // 总的回文字符个数+1
                        dp[i][j] = true;  // 标记当前开始和结束位置构成的字符串是回文串
                    }
                    //  2.2.如果长度超过2，则需要判断各自往里收缩一个字符得到的子串是否是回文串，
                    //      这里就用到了动态规划：即当前位置的状态取决于上一个位置的状态
                    else 
                    {
                        if(dp[i+1][j-1])    // 内部的子串是回文串
                        {
                            result++;   
                            dp[i][j] = true;
                        }
                        else    // 内部子串不是回文串
                        { 
                            dp[i][j] = false;
                        }
                    }

                }
                
            }
        }

        return result;
    }
};