/**
 * @file 40.hpp
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
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 类成员变量
    vector<vector<int>> result;   // 最终结果
    vector<int> path;
    int sum = 0;

    // 回溯函数
    void backtracking(vector<int>& candidates, int target, int start)
    {
        if(sum > target)   // 剪枝：提前终止
            return;
        if(sum == target)  // 递归终止条件
        {
            result.push_back(path);
            return;
        }

        // 开始递归
        for(int i = start; i < candidates.size(); i++)
        {
            // 去重：for循环选择的当前空的值等于前面一个元素的值，那么直接continue
            // 注意这里要i > start，因为当前空从start+1的位置开始，才能和前一个比较，否则都没有前一个
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, i+1);   // 组合中不能重复选择元素，所以是i+1
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // 1.排序数组
        sort(candidates.begin(), candidates.end());   
        backtracking(candidates, target, 0);   
        return result;
    }
};