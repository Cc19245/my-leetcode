/**
 * @file 54.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * 给你一个m*n的矩阵，顺时针返回它的所有元素
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 顺时针螺旋，使用[left, right)的形式
        int m = matrix.size();     // 矩阵的行
        int n = matrix[0].size();  // 矩阵的列
        vector<int> res(m*n, 0);   // 最终结果的初始化！
        int min_mn = m < n ? m : n;
        int loop = min_mn / 2;
        int offset = 1;  // 到头差多少

        int start_x = 0;
        int start_y = 0;
        int index = 0;
        while(loop--)
        {
            int i = start_x;    // i是行
            int j = start_y;    // j是列
            // 上边行
            for(; j < n - offset; j++)
            {
                res[index++] = matrix[i][j];
            }

            // 右边列
            for(; i < m - offset; i++)
            {
                res[index++] = matrix[i][j];
            }
    
            // 下边行
            for(; j > start_y; j--)
            {
                res[index++] = matrix[i][j];
            }
           
            // 左边列
            for(; i > start_x; i--)
            {
                res[index++] = matrix[i][j];
            }
            
            //更新完
            start_x++;
            start_y++;
            offset++;
        }

        if(index >= m*n)
            return res;
            
        // 针对奇数还是要单独处理
        if(m % 2 || n % 2)
        {
            if(m == n)
            {
                res[index] = matrix[m/2][n/2];
            }
            else if(m > n)   // 以n为准，还差右边一列
            {
                // 右边列
                for(int i = start_x; i <= m - offset; i++)
                {
                    res[index++] = matrix[i][start_y];
                }
            }
            else   // 以m为准，还差上面一行
            {
                // 上边行
                for(int j = start_y; j <= n - offset; j++)
                {
                    res[index++] = matrix[start_x][j];
                }
            }
        }

        return res;
    }
};