/**
 * @file 763.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int hash[26] = {0};  // 26个字符，出现的末尾位置先都初始化成0
        for(int i = 0; i < s.size(); i++)
            // 直接赋值为i就行，因为如果有重复字符，由于i越来越大，结果就是我们要统计的最远位置
            hash[s[i] - 'a'] = i;  
        
        int left = 0;  // 子串左边界
        int right = 0; // 子串右边界
        vector<int> result;  // 最终结果
        for(int i = 0; i < s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']);   // 更新最大子串的位置
            if(i == right)   // 当前位置到达了子串的最大位置
            {
                result.push_back(right - left + 1);  // 子串长度
                left = i + 1;  // 下一个子串的起始位置
            }
        }

        return result;
    }
};
