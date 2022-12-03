#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // 定义dp数组，并且全部初始化成0
        vector<int> dp(s.size(), 0);  // string.length()和string.size()结果是一样的，不存在任何区别
        int result = 0;   // 记录最长的长度

        // 开始遍历，执行动态规划
        for(int i = 1; i < s.size(); i++)   // i = 0的位置不管是什么子串，肯定都不是有效括号，所以直接跳过即可
        {
            if(s[i] == ')')  // 只有)需要处理，因为以(结尾的子串一定不能构成有效的子串
            {
                // 前一个是(，则i和i-1直接可以构成一个()，所以有效子串长度就是i-2结尾的有效子串长度+2
                if(s[i-1] == '(')
                {
                    if(i >= 2)  // 防止数组索引越界
                        dp[i] = dp[i-2] + 2;
                    else
                        dp[i] = 2;
                }   
                // 前一个是)，则需要判断i-1结尾的有效子串
                else
                {
                    // i-1结尾的子串长度是0，说明i-1结尾的就无法构成子串，由于i结尾的一定包含i-1，
                    // 所以也无法构成子串。因此这里我们只需要考虑构成子串的情况，即dp[i-1] > 0
                    if(dp[i-1] == 0)
                    {
                        dp[i] = 0;   // 可省略，由初始化赋值
                    }
                    else
                    {
                        // 当前)和前面的(构成匹配，同时要注意防止数组索引越界，比如())这种情况
                        if(i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '(')  
                        {
                            // i-1-dp[i-1]-1结尾的有效子串长度 + i-1结尾的有效子串长度 + 2
                            if(i-1-dp[i-1]-1 >= 0)   // 防止数组索引越界
                                dp[i] = dp[i-1-dp[i-1]-1] + dp[i-1] + 2;
                            else
                                dp[i] = dp[i-1] + 2;
                        }
                        else
                        {
                            dp[i] = 0;
                        }
                    }
                }
            }
            else
            {
                dp[i] = 0;   // 可省略，由初始化赋值
            }

            result = max(result, dp[i]);
        }

        return result;
    }


    int longestValidParentheses(string s)
    {
        // 定义dp数组，并且全部初始化成0
        vector<int> dp(s.size(), 0);  // string.length()和string.size()结果是一样的，不存在任何区别
        int result = 0;   // 记录最长的长度

        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                else
                {
                    if(i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '(')
                        dp[i] = (i-1-dp[i-1]-1 >= 0 ? dp[i-1-dp[i-1]-1] : 0) + dp[i-1] + 2;
                }
            }

            result = max(result, dp[i]);
        }

        return result;
    }

};