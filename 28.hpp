/**
 * @file 28.hpp
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
    int strStr(string haystack, string needle)
    {
        if(needle.size() == 0)
            return 0;

        int next[needle.size()];   // 新建next数组变量
        getNext(next, needle);     // 计算前缀表 
        int j = 0;   // needle数组中的索引
        // i是haystack数组中的索引
        for(int i = 0; i < haystack.size(); i++)
        {
            // 只要当前位置的字符不匹配，needle数组索引就根据next数组调到之前匹配的地方继续匹配
            while(j > 0 && haystack[i] != needle[j])
                j = next[j-1];
            
            // 当前位置匹配，needle数组索引向后一位，继续匹配下一位
            if(haystack[i] == needle[j])
                j++;
            
            // 如果needle数组已经遍历完成，则说明找到匹配的子串
            if(j == needle.size())
                return (i - needle.size() + 1);  // i - (needle.size()-1)
        }
        return -1;
    }

private:
    void getNext(int* next, const string& s)
    {
        // 1.初始化
        int j = 0;     // 前缀字符串末尾
        next[0] = 0;   // 第一个位置的最长相等前后缀一定是0

        // 遍历这个字符串，求前缀表
        for(int i = 1; i < s.size(); i++)
        {
            // 2.前后缀字符不相等，使用KMP的思想回退前缀字符的尾指针，直到和后缀字符匹配上
            while(j > 0 && s[j] != s[i])
                j = next[j-1];
            
            // 3.前后缀字符相等，则前缀指针后移，同时也表示i这个位置的最长相等前后缀就是j
            if(s[j] == s[i])
                j++;

            // 4.i这个位置的最长相等前后缀的长度就是j
            next[i] = j;
        } 
    }
};