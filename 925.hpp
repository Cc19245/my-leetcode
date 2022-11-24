#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0, j = 0;   // name, typed两个数组的索引

        // 遍历两个数组，哪个都不能超过范围
        while(i < name.size() && j < typed.size())
        {
            // 1.如果相等，则继续比较下一个
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            // 2.如果不相等
            else
            {
                // 2.1.如果是第一个字母就不相等，直接返回false
                if(j == 0)
                    return false;
                // 2.2.如果不是第一个字母，则可能是由于typed[j]是前一个字母的重复字母，此时就向后跳过重复的字母
                else
                {
                    // typed[j]向后跳过重复的字母
                    while(j < typed.size() && typed[j] == typed[j-1])
                        j++;
                    // typed[j]跳过重复的字母之后，再和name[i]比较
                    // 2.2.1.如果相等，则继续比较下一个
                    if(name[i] == typed[j])
                    {
                        i++;
                        j++;
                    }
                    // 2.2.2.如果不相等，则直接不满足要求，返回false
                    else
                    {
                        return false;
                    }
                }
            }
        }

        // 3.遍历之后，可能存在name没有遍历完，或者typed没有遍历完的情况
        // 3.1.name没有遍历完，显然typed太短了，直接返回false
        if(i < name.size())
            return false;
        
        // 3.2.tpyed没有遍历完，那么后面剩余的字符必须都是上面遍历的最后一个字符
        while(j < typed.size())
        {
            if(typed[j] != typed[j-1])  // 一旦不是上面遍历的最后一个字符，直接返回false
                return false;
            j++;
        }

        // 4.最终运行到这里则满足要求，返回true
        return true;
    }
};