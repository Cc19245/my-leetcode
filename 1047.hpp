/**
 * @file 1047.hpp
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
#include <string>
#include <algorithm>

using namespace std;


class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> have;
        for(auto& ss : s)
        {
            // 如果栈是空的，或者当前字符不等于栈顶字符，那么就加入
            if(have.empty() || ss != have.top())
                have.push(ss);
            // 否则当前字符 == 栈顶字符，就要把栈顶字符弹出
            else   
                have.pop();
        }

        // 到这里，栈中剩下的元素就是最后删除了重复元素之后的结果
        string res = "";
        while(!have.empty())
        {
            res += have.top();
            have.pop();
        }
        // 还要把字符串反转一下， 才是最终结果
        reverse(res.begin(), res.end());
        return res;
    }
};