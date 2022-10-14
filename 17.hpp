/**
 * @file 17.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-13
 * 
 * 给定正整数[1, ..., 9]，返回和为n的k个数的所有组合，组合中不能有重复数字
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
    const string phone_map[10] = {
        "",  // 0
        "",  // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    vector<string> result;
    string path;

    void backtracking(string& digits, int index)
    {
        // 递归终止条件：找到了符合要求的
        if(index == digits.size())  // 或者说这里改成start == path.size()
        {
            result.push_back(path);
            return;
        }

        // 开始递归
        int num = digits[index] - '0';   // 得到按下的是哪个数字，用来索引phone_map中的字符串
        string this_string = phone_map[num];  // 当前索引的字符串

        for(auto& this_char : this_string)   // for循环遍历当前的空位所有的可能字符
        {
            path.push_back(this_char);
            backtracking(digits, index+1);  // 填下一个空
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        // 注意这个空的判断很重要
        if(digits.size() == 0)
            return result;
        backtracking(digits, 0);   // 从第0个空开始填
        return result;
    }
};