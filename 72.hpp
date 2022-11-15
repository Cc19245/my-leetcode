#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // 1.dp数组定义
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

        // 2.dp数组初始化
        for(int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;  // word2是空，只能是word1一直在删除
        for(int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;  // word1是空，只能是word1一直在添加

        // 3.动态规划：使用递推公式开始递推
        for(int i = 1; i <= word1.size(); i++)
        {
            for(int j = 1; j <= word2.size(); j++)
            {
                // 1.word1字符等于word2字符，则不需要对word1当前位置做任何增删改操作
                if(word1[i-1] == word2[j-1])   
                    dp[i][j] = dp[i-1][j-1];
                    
                // 2.否则对word1有增删改三种情况，取他们操作的最小值：
                // (1)word1修改当前字符，让当前字符变成和word2的当前字符相等，那么此时匹配的最小修改次数
                //    就相当于word1/2都是用前面的子串进行匹配的次数，结果是dp[i-1][j-1]+1
                // (2)word1删除当前字符，即word1之前的子串匹配当前位置的word2，结果是dp[i-1][j]+1
                // (3)word1增加一个字符，其实这等效于把Word2删除当前字符，从而再与word1匹配，所以和(1)
                //    非常相似，只不过是删除word2中当前位置的字符，结果是dp[i][j-1]+1
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }

        // 最后返回结果
        return dp[word1.size()][word2.size()];
    }
};