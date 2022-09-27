/**
 * @file jz05.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        int count = 0;
        for(auto& ss : s)
        {
            if(ss == ' ')
                count++;
        }

        int end_old = s.size() - 1;     // 先记录扩充之前s的尾部指针的位置
        s.resize(s.size() + count*2);   // 注意从空格变成%20，多了俩字符，所以是*2，而不是*3
        int end_new = s.size() - 1;     // 扩充之后s的尾部指针的位置

        // 双指针法
        while(end_old >= 0)
        {
            if(s[end_old] != ' ')
                s[end_new--] = s[end_old--];
            else
            {
                s[end_new--] = '0';
                s[end_new--] = '2';
                s[end_new--] = '%';
                end_old--;
            }
        }

        return s;
    }
};