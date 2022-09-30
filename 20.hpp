/**
 * @file 20.hpp
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
#include <stack>

using namespace std;


class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> right;
        for(auto& ss : s)
        {
            // 左边字符的情况
            if(ss == '(')
                right.push(')');
            else if(ss == '{')
                right.push('}');
            else if(ss == '[')
                right.push(']');

            // 右边字符的情况
            // 1.stack为空，说明右边字符太多了
            else if(right.empty())
                return false;
            // 2.stack栈顶的元素不等于当前元素，说明就是字符不对称
            else if(right.top() != ss)
                return false;
            // 正常情况：弹出栈顶元素，遍历下一个元素
            else   
                right.pop();
        }

        // 3.stack有剩余元素，说明左边字符太多了。如果遍历完了stack也是空，说明就是对称的字符串
        return right.empty();
    }
};