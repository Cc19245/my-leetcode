#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> umap;  // 存储数字和出现的频率
        unordered_set<int> fre;  // 存储出现的频率

        // 1.统计数字出现的频率
        for(const auto& num : arr)
        {
            if(umap.find(num) == umap.end())
                umap.insert({num, 0});
            else
                umap[num]++;
        }

        // 2.遍历umap，看其中的值是否有重复的
        auto it = umap.begin();
        for(; it != umap.end(); it++)
        {
            if(fre.find(it->second) != fre.end())   // 如果有出现的频率，直接返回
                return false;
            fre.insert(it->second);  // 如果没有则插入这个新的频率
        }      

        // 运行到这里说明没有重复的频率，返回true
        return true;  
    }
};