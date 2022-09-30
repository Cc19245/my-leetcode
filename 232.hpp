/**
 * @file 232.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-30
 * 
 * 用栈实现队列
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stack_in_.push(x);
    }

    int pop()
    {
        if(stack_out_.empty())
        {
            // 如果出栈是空，则把入栈中的所有元素都拷贝到出栈中
            while(!stack_in_.empty())
            {
                int num = stack_in_.top();
                stack_in_.pop();
                stack_out_.push(num);
            }
        }
        // 至此stack_out_中肯定有元素了
        int res = stack_out_.top();
        stack_out_.pop();
        return res;
    }

    int peek()
    {
        int res = this->pop();
        stack_out_.push(res);
        return res;
    }

    bool empty()
    {
        // 如果入栈出站都是空，则队列就是空
        if(stack_out_.empty() && stack_in_.empty())
            return true;

        return false;
    }

private:
    stack<int> stack_in_;
    stack<int> stack_out_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */