#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> result(nums.size(), -1);   // 定义最终结果并初始化成-1
        if(nums.empty())
            return result;
        stack<int> st;   // 单调栈
        st.push(0);   // 先把第一个数的索引加进去

        // 开始数组：这里遍历两次，表示循环数组
        for(int i = 1; i < 2*nums.size(); i++)
        {
            int cur = i % nums.size();
            int top = st.top();
            // 如果当前数字 < 栈顶数组，则满足单调栈要求，可以入栈
            if(nums[cur] <= nums[top])
            {
                st.push(cur);
            }
            else
            {
                while(!st.empty() && nums[cur] > nums[top])
                {
                    result[top] = nums[cur];   // 记录结果
                    st.pop();   // 出栈
                    // 注意：问题就出在这里，因为此时弹出之后栈可能为空了，导致内存越界错误
                    top = st.top();   // 更新栈顶的索引  
                }
                st.push(cur);
            }
        }

        return result;
    }


    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> result(nums.size(), -1);   // 定义最终结果并初始化成-1
        if(nums.empty())
            return result;
        stack<int> st;   // 单调栈
        st.push(0);   // 先把第一个数的索引加进去

        // 开始数组：这里遍历两次，表示循环数组
        for(int i = 1; i < 2*nums.size(); i++)
        {
            int cur = i % nums.size();
            // 如果当前数字 < 栈顶数组，则满足单调栈要求，可以入栈
            if(nums[cur] <= nums[st.top()])
            {
                st.push(cur);
            }
            else
            {
                while(!st.empty() && nums[cur] > nums[st.top()])
                {
                    result[st.top()] = nums[cur];   // 记录结果
                    st.pop();   // 出栈
                }
                st.push(cur);
            }
        }

        return result;
    }
};