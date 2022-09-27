/**
 * @file jz58.hpp
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
    string reverseLeftWords(string s, int n)
    {
        reverseString(s, 0, n-1);
        reverseString(s, n, s.size()-1);
        reverseString(s, 0, s.size()-1);
        return s;
    }

private:
    // 翻转[start, end]内的字符
    void reverseString(string& s, int start, int end)
    {
        while(start < end)
        {
            char tmp = s[start];
            s[start++] = s[end];
            s[end--] = tmp;
        }
    }
};