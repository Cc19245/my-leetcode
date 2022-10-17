/**
 * @file 78.hpp
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

using namespace std;


class Solution
{

public:
    // 全局变量，存储最终结果和每次回溯路径收集的结果
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int start)
    {
        result.push_back(path);   // 每调用一次递归函数，都先把上一次的结果存起来
        if(start >= nums.size())
            return;

        for(int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtracking(nums, 0);
        return result;
    }


   
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int start)
    {
        if(start >= nums.size())
            return;

        for(int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);   // 把结果存起来
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.push_back(path);
        backtracking(nums, 0);
        return result;
    }
};