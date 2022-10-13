/**
 * @file 77.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-13
 * 
 * 给定正整数n，k，返回1,...,n中大小为k的所有组合
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
    
    // 全局变量，存储最终结果和每次回溯路径收集的结果
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int start)
    {
        // 2.递归终止条件：路径上收集的元素个数足够了
        if(path.size() == k)
        {
            // 存储这次路径收集的结果，存到最终result中
            result.push_back(path);
            return;
        }

        // 3.开始递归
        for(int i = start; i <= n; i++)
        {
            path.push_back(i);   // 先把当前遍历的这个元素存到path路径中
            backtracking(n, k, i+1);  // 然后从这个元素后面继续收集
            path.pop_back();     // 上面递归结束，说明收集的path满足要求，开始回溯，把最近的一个值弹出
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);  // 从1开始收集所有的可能的路径
        return result;
    }
};