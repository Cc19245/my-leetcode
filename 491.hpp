/**
 * @file 491.hpp
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
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int start)
    {
        // 和子集问题不同：这里收集结果是有条件的收集
        if(path.size() > 1)
        {
            // 能够运行到这里，说明path中收集的都是满足条件的子集，直接保存
            result.push_back(path);  
            // return;   // 错误警示：这里没有return!
        }

        // 递归终止条件：start已经到最后了，没有元素能够再选了。其实这里加不加这个终止条件无所谓，
        // 因为即使不加，后面的for循环也不会执行，最后这个函数也会直接返回
        if(start >= nums.size())
            return;


        // 临时变量：记录当前位置已经选择的数，当递归再次调用此函数的时候会新建另一个set来记录下个位置已经选择的数
        unordered_set<int> already_set;   
        for(int i = start; i < nums.size(); i++)
        {
            // continue条件：1.当前的数 < path中最后一个，说明不满足递增条件
            //              2.当前的数字已经使用过，不能再使用，即去重
            if((!path.empty() && nums[i] < path.back()) || already_set.find(nums[i]) != already_set.end())
                continue;
            already_set.insert(nums[i]);   // 记录当前位置已经选择的数
            path.push_back(nums[i]);
            backtracking(nums, i + 1);     // 选择下一个位置的数
            path.pop_back();   // 回溯
            
            // 注意：这里没有already_set的删除操作，即这里回溯和already_set无关。因为already_set是和
            // for循环有关的，是记录当前位置选择数；而回溯切换当前位置选择的下一个可能的数之前，把当前选择
            // 的数字弹出。而already_set的目的就是记录之前已经选择过的数，所以回溯的时候不能删除里面的数
        } 
    }

    void backtracking(vector<int>& nums, int start)
    {
        if(path.size() > 1)
        {
            // 先判断是否是递增的，如果不是，直接返回。注意这个返回是说以这个子集开头的其他所有子集也都不是递增的，
            // 所以没有必要继续往下递归了，所以才直接返回。对于子集问题来说，是没有特定的递归终止条件的，这里的
            // return只是为了剪枝加速
            for(int i = 0; i < path.size() - 1; i++)
                if(path[i] > path[i+1])
                    return;
            // 执行到这个地方，说明path中是递增的了，可以加入result
            result.push_back(path);
        }
        if(start >= nums.size())
            return;   // 有没有都行的递归终止条件
        
        unordered_set<int> already_set;
        for(int i = start; i < nums.size(); i++)
        {
            if(already_set.find(nums[i]) != already_set.end())  // 如果当前选择数之前已经选过了
                continue;
            
            already_set.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtracking(nums, 0);
        return result;
    }
};