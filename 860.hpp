/**
 * @file 860.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0, twenty = 0;

        for (auto &bill : bills)
        {
            // 5元：直接收下
            if (bill == 5)
            {
                five++;
            }
            // 10元：判断如果可以找零则收下，否则直接返回
            else if (bill == 10)
            {
                if (five > 0) // 还有5元的
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }
            // 20元：判断如果可以找零则收下，否则直接返回
            else
            {
                if (five > 0 && ten > 0)  // 1.优先用10+5找零
                {
                    five--;
                    ten--;
                    twenty++;
                }
                else if (five >= 3)   // 2.再用5+5+5找零
                {
                    five -= 3;
                    twenty++;
                }
                else   // 3.最后无法找零，返回false
                {
                    return false;  
                }
            }
        }

        return true;
    }
};