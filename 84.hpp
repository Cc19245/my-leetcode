#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        //? 疑问1：为什么要头部加0，尾部加0？代码随想录中也没有给出讲解
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0);               // 数组尾部加入元素0
        st.push(0);
        int result = 0;

        // 第一个元素已经入栈，从下标1开始
        for (int i = 1; i < heights.size(); i++)
        {
            // 注意heights[i] 是和heights[st.top()] 比较 ，st.top()是下标
            if (heights[i] > heights[st.top()])
            {
                st.push(i);
            }
            //? 疑问2：当相等的时候不是也可以构成矩形吗？为什么要弹出？
            else if (heights[i] == heights[st.top()])
            {
                st.pop(); // 这个可以加，可以不加，效果一样，思路不同
                st.push(i);
            }
            else
            {
                //? 疑问3：为什么这里没有判断!st.empty()？这样不会导致栈为空的访问错误吗？
                while (heights[i] < heights[st.top()])   // 注意是while
                { 
                    int mid = st.top();
                    st.pop();
                    int left = st.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[mid];
                    result = max(result, w * h);
                }
                st.push(i);
            }
        }
        return result;
    }
};