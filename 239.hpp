/**
 * @file 239.hpp
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
#include <deque>

using namespace std;


class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        MyQueue que;

        // 1.先把第一个滑窗中的元素加到que中
        for(int i = 0; i < k; i++)
            que.push(nums[i]);
        res.push_back(que.front());

        // 2.遍历后面的滑窗
        for(int i = k; i < nums.size(); i++)
        {
            // 弹出上一个滑窗中前面的元素
            que.pop(nums[i-k]);
            // 加入新的元素
            que.push(nums[i]);
            // 计算滑窗中新的最大值
            res.push_back(que.front());
        }

        return res;
    }

private:
    class MyQueue
    {
    public:
        void pop(int x)
        {
            // 只有队列最前面的数恰好是要弹出的元素的时候才真正弹出，
            // 因为其他元素在push的时候根本就没有push进到队列中
            if(!que.empty() && que.front() == x)
                que.pop_front();
        }

        void push(int x)
        {
            // 1.注意这里是用while，直到满足要求
            // 2.其次注意这里是判断que.back，而不是que.front，这样结果才能是单调的序列
            // 3.注意这里是<，而不是<=，因为队列是单调不增的就可以，而非严格单调的
            while(!que.empty() && que.back() < x)
                que.pop_back();
            que.push_back(x);
        }

        int front()
        {
            return que.front();
        }
        deque<int> que;
    };
};