/**
 * @file 150.hpp
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
#include <vector>

using namespace std;


class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int res;
        stack<int> nums;
        for(int i = 0; i < tokens.size(); i++)
        {
            string s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/")
            {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
 
                if(s == "+") 
                    nums.push(num1 + num2);
                else if(s == "-")
                    nums.push(num1 - num2);
                else if(s == "*")
                    // 这里要转成long，不然有可能会报溢出错误
                    nums.push((long)num1 * num2);
                else
                    nums.push(num1 / num2);
            }
            // 不是标点符号，就转成数字
            else
                nums.push(stoi(s));   
        }
        // 最后遍历完，stack中就剩下一个数字，就是最终答案
        return nums.top();
    }
};