#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string str = to_string(n);   // 先转成字符串，方便后面取每一位的数
        int change_index = str.size();   // 变成9的位置索引

        // 1.从后往前遍历，看那些位置需要减一变9
        for(int i = str.size() - 1; i > 0; i--)  // 从最后一位开始，从后往前遍历
        {
            if(str[i-1] > str[i])
            {
                change_index = i;   // 记录变9的位置
                str[i-1]--;  // 前面位置的数字-1
            } 
        }

        // 2.从最前面变9的位置开始，后面全都设置成9
        for(; change_index < str.size(); change_index++)
        {
            str[change_index] = '9';
        }

        return stoi(str);   // 返回最终结果
    }
};