#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:

    int count;   // 最后的结果

    bool isValid(int row, int col, int n, vector<string>& chess)
    {
        // 判断列是否合法
        for(int i = 0; i < row; i++)
            if(chess[i][col] == 'Q')
                return false;
        // 判断左上是否合法
        for(int i = row-1, j=col-1; i >=0 && j>=0; i--, j--)
            if(chess[i][j] == 'Q')
                return false;
        // 判断右上是否合法
        for(int i = row-1, j=col+1; i >=0 && j<n; i--, j++)
            if(chess[i][j] == 'Q')
                return false;
        return true;
    }


    void backtracking(int row, int n, vector<string>& chess)
    {
        // 2.回溯终止条件：放到了最后一行
        if(row == n)
        {
            count++;  // 放满了棋盘格，得到一个合理的解
        }

        // 3.开始递归：遍历这一行的所有列
        for(int col = 0; col < n; col++)
        {
            if(isValid(row, col, n, chess))  // 判断当前位置放一个皇后是否合法
            {
                chess[row][col] = 'Q';   // 放置皇后
                backtracking(row+1, n, chess);   // 递归
                chess[row][col] = '.';   // 回溯
            }
        } 
    }

    int totalNQueens(int n)
    {
        vector<string> chess(n, string(n, '.'));  // 初始化棋盘格
        backtracking(0, n, chess);  // 然后开始遍历，放置皇后
        return count;   // 最后返回所有可能的结果
    }
};