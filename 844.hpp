#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        // 使用string当做栈，存储没有#的结果
        string ss;
        string tt;

        // 对string s进行去#操作
        for(const auto& ch : s)
        {
            if(ch != '#')  // 如果不是#，则正常入栈
                ss += ch;   // 这里应该蕴含一个隐式类型转换，char转成string
            else   // 如果是#，则执行删除上一个字符的功能，也就是出栈
                if(!ss.empty())   // 出栈之前判断栈非空
                    ss.pop_back();
        }

        // 同理对string t进行去#操作
        for(const auto& ch : t)
        {
            if(ch != '#')
                tt += ch;
            else
                if(!tt.empty())
                    tt.pop_back();
        }

        // 最后判断两个字符串是否相等
        return ss == tt;
    }


    bool backspaceCompare(string s, string t)
    {
        // 从后往前遍历，当前位置要消除的元素个数
        int skip_s = 0;
        int skip_t = 0;

        // s/t最后一个元素的索引
        int i = s.size() - 1;
        int j = t.size() - 1;

        while(true)
        {
            // 1.对s的字符往前遍历，寻找满足要求的字符
            while(i >= 0)
            {
                if(s[i] == '#')   // 当前为#，则累加要删除的元素个数，指针前移
                {
                    skip_s++;
                    i--;
                }
                else   // 当前不是#，则根据要删除的元素个数，指针前移
                {
                    if(skip_s > 0)  // 需要前移，则前移
                    {
                        skip_s--;
                        i--;
                    }
                    else    // 不需要前移，则找到了当前需要比较的的s[i]
                    {
                        break;
                    }
                }
            }

            // 2.对t的字符执行上述相同的操作
            while(j >= 0)
            {
                if(t[j] == '#')   // 当前为#，则累加要删除的元素个数，指针前移
                {
                    skip_t++;
                    j--;
                }
                else   // 当前不是#，则根据要删除的元素个数，指针前移
                {
                    if(skip_t > 0)  // 需要前移，则前移
                    {
                        skip_t--;
                        j--;
                    }
                    else    // 不需要前移，则找到了当前需要比较的的t[j]
                    {
                        break;
                    }
                }
            }

            // 3.运行到这里，找到了需要匹配的s[i]和t[j]
            if(i == -1 && j == -1)  // 如果都到了尽头，说明相等
            {
                return true;
            }
            else if(i != -1 && j != -1)  // 如果都没有到尽头，则需要判断是否相等
            {
                if(s[i] != t[j])
                {
                    return false;
                }
                else   // 否则当前字符相等，就要i--，j--，继续判断之前的字符
                {
                    i--;
                    j--;
                }
            }
            else   // 如果一个到尽头，一个没到尽头，肯定不相等
            {
                return false;
            }  
        }

        return true;   //不可能运行到这里
    }
};