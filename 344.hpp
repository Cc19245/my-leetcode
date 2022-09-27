/**
 * @file 344.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * 原地反转字符串
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
        {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};