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
#include <unordered_set>

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
            // 跳过的两种情况：
            // 1.当前位置的数字已经使用过，那么不能再使用
            // 2.去重：当前位置的数字等于上一个数字，那么上一个数字的排列结果和当前数字的排列结果中有重复的，
            //        直接去掉当前位置的数字的选择
            if(used[i] || (i>0 && nums[i] == nums[i-1] && used[i-1] == false)) 
                continue;
            
            path.push_back(nums[i]);
            used[i] = true;   // 标记当前数字已经使用过
            backtracking(nums, used);   // 选择下一个数字
            path.pop_back();   // 回溯，弹出当前选择的数字
            used[i] = false;   // 回溯，标记当前选择的数字没有使用过
        }
    }

    void backtracking(vector<int> &nums, vector<bool>& used)
    {
        if(path.size() >= nums.size())
        {
            result.push_back(path);
            return;
        }

        // 临时变量，记录全排列中当前位置已经选过的元素
        unordered_set<int> already_set;   
        for(int i = 0; i < nums.size(); i++)
        {
            // 跳过的两种情况：
            // 1.当前位置的数字已经使用过，那么不能再使用
            // 2.去重：当前位置的数字在之前已经选择过
            if(used[i] || already_set.find(nums[i]) != already_set.end()) 
                continue;
            
            already_set.insert(nums[i]);   // 记录当前数字已经选择过
            path.push_back(nums[i]);
            used[i] = true;   // 标记当前数字已经使用过
            backtracking(nums, used);   // 选择下一个数字
            path.pop_back();   // 回溯，弹出当前选择的数字
            used[i] = false;   // 回溯，标记当前选择的数字没有使用过
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);  // 先全部初始化没有使用过
        sort(nums.begin(), nums.end());   // 对数组进行排序
        backtracking(nums, used);
        return result;
    }
};