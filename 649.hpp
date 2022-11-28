#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        bool haveR = true;
        bool haveT = true;
        int numR = 0;   // 当前位置之前（包括当前位置）含有的R的个数
        int numT = 0;   // 当前位置之前（包括当前位置）含有的T的个数

        // 只要数组中还有R并且还有T，那么就还没有消灭完毕，则继续消灭
        while(haveR && haveT)
        {
            // 先认为没有R和T了，如果后面执行过程中被修改成true了，则说明还有R和T
            haveR = false;
            haveT = false;  
            for(int i = 0; i < senate.size(); i++)
            {
                if(senate[i] == 'R')
                {
                    numR++;   // 首先字符R的个数++
                    if(numT >= numR)   // 如果当前位置前面的T个数 >= 当前位置R的个数，则可以消灭
                    {
                        senate[i] = 0;  // 消灭R，为下一次循环做准备
                        numR--;
                    }
                    else
                        haveR = true;   // 否则不能消灭R，置位
                }
                else if(senate[i] == 'T')
                {
                    numT++;
                    if(numR >= numT)
                    {
                        senate[i] = 0;
                        numT--;
                    }
                    else
                        haveT = true;
                }
            }
        }

        return haveR == true ? "Radiant" : "Dire";  // 根据最后haveR还是T返回结果
    }
};