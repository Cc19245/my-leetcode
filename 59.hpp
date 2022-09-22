/**
 * @file 59.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-22
 * 
 * 
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
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0;                    // 定义每循环一个圈的起始位置
        int loop = n / 2;                              // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2;                               // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1;                                 // 用来给矩阵中每一个空格赋值
        int offset = 1;                                // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i, j;
        while (loop--)
        {
            i = startx;
            j = starty;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < n - offset; j++)
            {
                res[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++)
            {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--)
            {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--)
            {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));  // 初始化最终的结果，使用vector来模拟二维矩阵
        int loop = n / 2;   // 循环的圈数，因为每次循环上下(或左右)一共填充2行(或列)，因此循环次数是n/2
        int startx = 0;
        int starty = 0;
        int i, j;
        int num = 1;      // 填充的数字
        int offset = 1;   // 每次循环填充的时候到边界的距离
        while(loop--)
        {
            i = startx;
            j = starty;

            // 填充上面的一行，左闭右开
            for(; j < n - offset; j++)
            {
                res[i][j] = num++;
            }
            // 右边一列，左闭右开
            for(; i < n - offset; i++)
            {
                res[i][j] = num++;
            }
            // 下边一行，左闭右开
            for(; j > starty; j--)
            {
                res[i][j] = num++;
            }
            // 左边一列，左闭右开
            for(; i > startx; i--)
            {
                res[i][j] = num++;
            }

            // 循环完一次，起始位置和距离边界的位置都+1
            startx++;
            starty++;
            offset++;
        }

        if(n % 2)   // 如果是奇数，中间位置需要单独赋值
        {
            res[n/2][n/2] = num;
        }    

        return res;   
    }
};