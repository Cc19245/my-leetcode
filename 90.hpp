/**
 * @file 90.hpp
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

    void backtracking(vector<int>& nums, int start)
    {
        result.push_back(path);    // 一进来就收集上次的结果
        if(start >= nums.size())
            return;

        // 递归
        for(int i = start; i < nums.size(); i++)
        {
            // 去重：当前位置的元素不能和上一次选择的一样
            if(i > start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);  // 再选择下一个元素
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};