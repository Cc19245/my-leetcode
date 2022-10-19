/**
 * @file 51.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-19
 * 
 * n皇后问题
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
    vector<vector<string>> result;  // 最终收集的所有可能的放置方案
    vector<string> chess_board;     // 当前放置的棋盘格，就是之前组合问题中的path

    // 传入棋盘格的大小，当前要放置皇后的行，当前要放置皇后的列，已经放置的棋盘格，
    //    判断是否能够在当前位置放置皇后
    bool isValid(int n, int row, int col)
    {
        // 判断列
        for(int i = 0; i < row; i++)
            if(chess_board[i][col] == 'Q')  // 每一行的当前列
                return false;

        // 注意：这里不用判断行是否在同一行，因为我们是逐行放置皇后，即遍历当前行的时候，之前一定是没有放置过的

        // 判断左上角对角线
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
            if(chess_board[i][j] == 'Q')
                return false;

        // 判断右上角对角线
        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++)
            if(chess_board[i][j] == 'Q')
                return false;

        return true;
    }
    void backtracking(int n, int row)
    {
        // 递归终止条件：遍历到第n行了（从0开始），说明棋盘已经放置满了，所以是一种合理的结果
        if(n == row)
        {
            result.push_back(chess_board);
            return;
        }

        // 遍历当前行的每一个位置，判断是否可以放置皇后
        for(int col = 0; col < n; col++)
        {
            if(isValid(n, row, col))   // 如果当前位置可以放置皇后
            {
                chess_board[row][col] = 'Q';   // 放置皇后
                backtracking(n, row + 1);      // 放置下一行的皇后
                chess_board[row][col] = '.';   // 回溯，删除当前位置放置的皇后
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        // 初始化nxn的棋盘格为空，没有放置任何皇后
        for(int i = 0; i < n; i++)
            chess_board.push_back(string(n, '.'));

        result.clear();
        backtracking(n, 0);  // 从棋盘格第0行开始放置皇后
        return result;
    }
};