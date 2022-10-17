/**
 * @file 131.hpp
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
    // [start, end]，传入一个字符串和它的起止位置，判断是否是回文串
    bool isPalindrome(string& s, int start, int end)
    {
        if(end >= s.size())
            return false;
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(string& s, int start)
    {
        // 递归终止条件：切割到字符串最后了，说明前面切割的各个子串都是回文串，则当前path符合条件，加入result中
        if(start >= s.size())
        {
            result.push_back(path);
            return;
        }

        // 递归
        for(int i = start; i < s.size(); i++)
        {
            // 剪枝：如果当前切割的子串是回文串，那么把结果加到path中，并正常调用递归切割当前位置后面的子串
            if(isPalindrome(s, start, i))
                path.push_back(s.substr(start, i - start + 1));
            // 否则，直接continue，换下一个位置重新切割当前的子串
            else   
                continue; 
            backtracking(s, i+1);
            path.pop_back();  // 回溯
        }
    }


    vector<vector<string>> result;   // 最终结果
    vector<string> path;   // 本次路径切割的子串
    // [start, end]，判断一个字符串是否是回文字符串
    bool isPalindrome(string& s)
    {
        int start = 0;
        int end = s.size() - 1;
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void backtracking(string& s, int start)
    {
        // 递归终止条件：切割到字符串最后了，说明切完了
        if(start >= s.size())
        {
            bool is_valid = true;    // 当前path中的子串是否都是回文子串
            for(auto& sub_string : path)
            {
                // 只要有一个不是回文，那本次切割结果就不是回文
                if(!isPalindrome(sub_string))  
                {
                    is_valid = false;
                    break;
                }
            } 
            if(is_valid)   // 如果本次切割是回文，就把结果加到result中
                result.push_back(path);
            return;
        }

        // 递归
        for(int i = start; i < s.size(); i++)
        {
            // 把当前切割的子串放到path中
            path.push_back(s.substr(start, i - start + 1));  
            backtracking(s, i+1);  // 调用递归，继续切割当前位置后面的字符串
            path.pop_back();  // 回溯
        }
    }
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return result;
    }
};