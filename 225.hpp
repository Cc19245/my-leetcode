/**
 * @file 225.hpp
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
#include <queue>

using namespace std;

class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1_.push(x);
    }

    // 方法1：使用两个队列
    // int pop()
    // {
    //     int size = q1_.size();
    //     size--;
    //     // 把q1的前面(size-1)个元素都弹出，然后存到q2中
    //     while(size--)
    //     {
    //         q2_.push(q1_.front());
    //         q1_.pop();
    //     }
    //     // 把q1中的最后一个元素弹出，就是目标值
    //     int res = q1_.front();
    //     q1_.pop();

    //     // 再把弹出后的剩余的所有袁术，即q2中的元素存回q1
    //     q1_ = q2_;

    //     // 最后把q2清空，留给下次备用
    //     while(!q2_.empty())
    //         q2_.pop();
    //     return res;
    // }

    // 方法2：使用一个队列
    int pop()
    {
        int size = q1_.size();
        size--;
        while(size--)
        {
            q1_.push(q1_.front());
            q1_.pop();
        }
        int res = q1_.front();
        q1_.pop();
        return res;
    }

    int top()
    {
        // 栈顶的元素，就是队列尾的元素
        return q1_.back();
    }

    bool empty()
    {
        return q1_.empty();
    }

private:
    queue<int> q1_;
    queue<int> q2_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */