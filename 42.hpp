#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sum = 0;  // 最后的总和

        // 遍历每一列，计算该列能接的雨水的值
        for(int i = 0; i < height.size(); i++)
        {
            // 最左边和最右边的不能接雨水
            if(i == 0 || i == height.size() - 1)
                continue;
            
            // 记录左右的最大高度
            int l_h = height[i];    
            int r_h = height[i];

            // 寻找左侧的最大高度
            for(int l = i - 1; l >= 0; l--)
                if(height[l] > l_h)
                    l_h = height[l];   

            // 寻找右侧的最大高度
            for(int r = i + 1; r < height.size(); i++)
                if(height[r] > r_h)
                    r_h = height[r];
            
            // 计算这一列接的雨水，加到总和中（注意这里计算的雨水高度一定是>=0的，所以不用判断>0）
            sum = sum + min(l_h, r_h) - height[i];
        }

        return sum;
    }

    int trap(vector<int> &height)
    {
        int sum = 0;  // 最终结果
        if(height.empty())
            return sum;
        stack<int> st;
        st.push(0);    // 先存入第一个元素

        // 遍历所有元素
        for(int i = 1; i < height.size(); i++)
        {   
            // 1.仍然保持下降：则无法构成凹槽，继续加入单调栈
            if(height[i] < height[st.top()])
            {
                st.push(i);
            }
            // 2.持平：需要更新右边界，因为下面计算宽度w的时候需要用右边界计算宽度，
            //        所以这里把原先的高度的索引弹出，然后加入当前的索引
            else if(height[i] == height[st.top()])
            {
                st.pop();
                st.push(i);
            }
            // 3.上升：则出现凹槽，对每一个凹槽按照行来计算
            else
            {
                while(!st.empty() && height[i] > height[st.top()])
                {
                    int mid = height[st.top()];   // mid就是凹槽的高度
                    st.pop(); 
                    // 注意这里弹出后要判断非空才继续算，比如最左边两个数是上升的，遍历到第2个数的时候
                    // 满足上数条件，即i=1, st.top()=0。但是这样明显是无法接雨水的，因为左边没有了
                    if(!st.empty())
                    {
                        // 计算高度，是左右边界的高度的最小值 - 中间凹槽的高度
                        int h = min(height[st.top()], height[i]) - mid;
                        // 计算宽度，注意-1，因为i是右边界，st.top()是左边界，只有中间才是宽度
                        int w = i - st.top() - 1;  
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }

        return sum;
    }
};