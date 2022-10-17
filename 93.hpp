/**
 * @file 93.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-17
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
    vector<string> result;   // 最终结果
    vector<string> path;     // 本次字符分割的结果，其中每个位置存放分割的子串
    int seg_num = 0;   // 分割的段数，达到4段就结束

    // [start, end]，判断字符串作为IP地址中一位是否有效
    bool isValid(string& s, int start, int end)
    {
        if(start > end)   // 区间不合法
            return false;
        if(start < end && s[start] == '0')  // 不是一个字符长度，但是以0开头，如023这种情况
            return false;
        int num = 0;
        for(int i = start; i <= end; i++)
        {
            num = num * 10 + (int)(s[i] - '0');  // 计算IP的大小
            if(num > 255)
                return false;
        }
        return true;
    }
    void backtracking(string &s, int start)
    {
        // 递归终止条件：已经分割了四段，并且到这个位置说明4段都是合法的IP地址
        if(seg_num >= 4)
        {
            // 分割了四段，而且都分割完了，说明这是一个合法地址，就拼接结果存到result中
            if(start >= s.size())  
            {
                // 添加.来拼接IP地址，存储到result中
                string ans = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
                result.push_back(ans);
            }
            return;
        }

        // 开始递归
        for(int i = start; i < s.size(); i++)
        {
            // 判断当前分割的子串是否符合条件
            if(isValid(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                seg_num++;  // 当前分割的子串符合条件，把seg_num+1
            }
            else   // 如果不符合条件，则继续分割当前字符串
                continue;
            backtracking(s, i+1);   // 分割当前字符串后面的子串
            seg_num--;   // 回溯
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        backtracking(s, 0);   // 从第0个字符开始分割
        return result;
    }
};