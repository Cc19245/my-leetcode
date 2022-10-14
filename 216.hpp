/**
 * @file 216.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-13
 * 
 * 给定正整数[1, ..., 9]，返回和为n的k个数的所有组合，组合中不能有重复数字
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
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    void backtracking(int n, int k, int start, int sum)
    {
        // 2.递归终止条件
        // 剪枝操作1：如果此时sum大于目标值，后面的组合也不用看了，肯定也大于（因为数组是升序排列的）
        if(sum > n)
            return;
        // 正常终止条件：收集个数达到k，判断sum是否等于n，如果等于则是合法结果，如果不等于则什么不处理
        if(path.size() == k)
        {
            if(sum == n)
                result.push_back(path);
            return;
        }
        
        // 3.开始递归：注意for循环中包括对组合长度k的剪枝操作
        for(int i = start; i <= 9-(k-path.size())+1; i++)
        {
            path.push_back(i);
            sum += i;   // sum值累加
            backtracking(n, k, i+1, sum);
            sum -= i;   // 回溯
            path.pop_back();  // 回溯
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(n, k, 1, sum);
        return result;
    }
};