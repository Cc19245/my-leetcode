/**
 * @file 459.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-30
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
    bool repeatedSubstringPattern(string s)
    {
        int len = s.size();
        if(len == 0)
            return false;

        int next[s.size()];
        getNext(next, s);
        int max = next[len - 1];   // 最长相等前后缀的长度
        // 注意最长相等前后坠的长度不能是0
        if(max != 0 && len % (len - max) == 0)
            return true;
            
        return false;
    }

private:
    void getNext(int* next, const string& s)
    {
        // 1.初始化next数组
        int j = 0;
        next[0] = 0;

        // 遍历后缀的位置
        for(int i = 1; i < s.size(); i++)
        {
            // 2.前后缀不相等，回退
            while(j > 0 && s[j] != s[i])
                j = next[j-1];  
            
            // 3.前后缀相等，j++表示i的位置的最长相等前后缀长度+1
            if(s[j] == s[i])
                j++;
            
            // 4.把i位置的最长想等前后缀赋值成j
            next[i] = j;
        }
    }
};