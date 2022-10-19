/**
 * @file 37.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-19
 * 
 * 解数独问题
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
    bool isValid(vector<vector<char>>& board, int row, int col, char num)
    {
        int n = board.size();

        // 同一行不能有相同的
        for(int j = 0; j < n; j++)
            if(board[row][j] == num)
                return false;
        
        // 同一列不能有相同的
        for(int i = 0; i < n; i++)
            if(board[i][col] == num)
                return false;
        
        // 同一个小的九宫格不能有相同的
        int start_row = row / 3;
        start_row *= 3;
        int start_col = col / 3;
        start_col *= 3;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(board[start_row + i][start_col + j] == num)
                    return false;

        return true;
    }

    // 正确解法
    bool backtracking(vector<vector<char>>& board)
    {
        // 遍历数独的每一行
        for(int row = 0; row < board.size(); row++)
        {
            // 遍历数独的每一列
            for(int col = 0; col < board[0].size(); col++)
            {
                // 当前位置原来就有数字，或者之前填过数字了，就不用填了
                if(board[row][col] != '.')  
                    continue;

                // 否则遍历1-9，查找哪些数字可能填入当前的空中
                for(char num = '1'; num <= '9'; num++)
                {
                    if(isValid(board, row, col, num))
                    {
                        board[row][col] = num;   // 修改棋盘格，当前位置填入num
                        // 递归，再次填数独，这样下次递归的函数里面直接会走上面的continue，因为这个位置已经填了数了
                        if(backtracking(board))
                            return true;
                        board[row][col] = '.';  // 回溯
                    }
                }

                // 重要：这里才是递归的终止条件，或者说是提前结束的剪枝操作。能够执行到这里，说明在上面的for循环中，
                //      选择1-9通过isValid判断都不合法，因为如果合法的话就会进去再次调用递归函数，然后继续递归。
                //      而如果不合法的话，上面的for循环中if判断都不合法，即在这个空的上一个空选择的数是错的，导致
                //      这次不管填什么数字都不满足数独要求了，所以才会出for循环运行到这里。那么此时就直接return
                //      fasle，告诉上次的递归函数选择的数字是错误的。
                // 其实这里也可以看出来，数独的唯一解就是每一次都选择正确的数字，所以每一次都满足isValid的条件
                // 所以就不断递归，直到把所有的空都填满，也就是for(i)和for(j)都循环完毕，也就到了最下面的return
                // true，再层层向上返回，得到唯一的解。
                return false;
            }

            // 注意：这里没有return false。因为上面的for循环填每一行的空位，虽然上面说了唯一的解就是每一个空位
            // 都满足isValid的条件，然后层层递归。但是也有可能这一行中没有空位，也就是都是走了continue的路线，
            // 那么这一行就不会调用任何递归函数，所以for(i)正常执行遍历下一行，此时也是合法的。所以这里不能直接
            // return fasle，也就是这里不需要做任何处理。
        }
        
        // 如果能够执行到这里，说明for(i)和for(j)都循环完毕了，也就是每一个空位都找到了合适的解，也就是
        // 整个数独问题找到了唯一的答案。所以这里return true，然后true会层层返回给上一层的递归函数，
        // 直到返回给最高层的递归函数
        return true;
    }

    // 自己写的错误解法，无法AC
    bool backtracking(int n, int row, int col, vector<vector<char>>& board)
    {
        if(row == n)
            return true;

        // 遍历当前行的所有空位，每一个空位都需要填一个数
        for(int j = col; j < n; j++)
        {
            if(board[row][j] != '.')
                continue;
            for(char num = '1'; num < '9'; num++)
            {
                if(isValid(board, row, j, num))
                {
                    board[row][j] = num;
                    if(backtracking(n, row, j + 1, board))
                        return true;
                    board[row][j] = '.';  // 回溯
                }
            }

            // 执行到这里，说明上述是错的，即使止损
            return false;
        }

        // 上面遍历完了这一行，然后从0开始继续遍历下一行
        if(backtracking(n, row + 1, 0, board))
            return true;
        
        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board.size(), 0, 0, board);
    }
};