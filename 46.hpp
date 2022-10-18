/**
 * @file 46.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-13
 * 
 * 子集问题
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
    // 全局变量，存储最终结果和每次回溯路径收集的结果
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool>& used)
    {
        if(path.size() >= nums.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i])  // 当前数字已经使用过，那么跳过
                continue;
            path.push_back(nums[i]);
            used[i] = true;   // 标记当前数字已经使用过
            backtracking(nums, used);   // 选择下一个数字
            path.pop_back();   // 回溯，弹出当前选择的数字
            used[i] = false;   // 回溯，标记当前选择的数字没有使用过
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);  // 先全部初始化没有使用过
        backtracking(nums, used);
        return result;
    }
};