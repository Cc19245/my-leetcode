/**
 * @file 347.hpp
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
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution
{
public:
    // 小顶堆的排序
    class MyCmp
    {
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 1.统计元素出现的频率
        unordered_map<int, int> map;
        for(auto& num : nums)
            map[num]++;
        
        // 2.构造小顶堆，这里的构建中vector<pair<int,int>>是啥？还是需要去学习一下这个数据结构
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> que;

        // 3.构建小顶堆，其本质就是一个堆，保持堆的大小为k，一旦超过了k个元素就pop
        auto it = map.begin();
        for(; it != map.end(); it++)
        {
            que.push(*it);
            if(que.size() > k)
                que.pop();
        }

        // 4.最后小顶堆中的k个pair就是所求，但是top的地方是最小的，所以要倒序存放
        vector<int> res(k);
        for(int i = k-1; i>=0; i--)
        {
            res[i] = que.top().first;
            que.pop();
        }

        return res;
    }
};