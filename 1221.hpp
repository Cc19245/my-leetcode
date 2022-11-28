#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int result = 0; // 最后平衡字符串的个数
        int count = 0;  // 字符串中R的个数

        // 遍历一遍字符串，寻找平衡子串
        for (const auto &ch : s)
        {
            if (ch == 'R')
                count++;
            else
                count--;
            if(count == 0)  // 遇到一个平衡子串
                result++;
        }
        
        return result;
    }
};