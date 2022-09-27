/**
 * @file 541.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * 翻转字符串2
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for(int i = 0; i < s.size(); i += 2*k)
        {
            if(i + k <= s.size())
                reverse(s.begin()+i, s.begin()+i+k);
            else
                reverse(s.begin()+i, s.end());
        }
        return s;
    }
};