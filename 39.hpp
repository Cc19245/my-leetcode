/**
 * @file 39.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-17
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
    
    // 类成员变量
    vector<vector<int>> result;   // 最终求解结果
    vector<int> path;   // 当前次遍历的路径
    int sum = 0;   // 当前遍历的路径的和
    
    // 回溯函数
    void backtracking(vector<int>& candidates, int target, int start)
    {
        if(sum > target)   // 剪枝：sum > target，则没有必要继续往下递归了，后面的肯定也是 sum > target
            return;
        if(sum == target)  // 递归终止条件：找到符合要求的组合，则放到最后结果中
        {
            result.push_back(path);
            return;
        }

        // 开始回溯
        for(int i = start; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);  // 填当前的空
            sum += candidates[i];
            backtracking(candidates, target, i);  // 递归填下一个空，注意这里是i，不是i+1，也不是start
            sum -= candidates[i];  // 回溯
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(candidates, target, 0);
        return result;
    }
};