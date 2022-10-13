/**
 * @file 108.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * 给定一个升序数组，构造一棵平衡的二叉搜索树
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
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    };

    // nums一定要引用传递，[left, right)区间
    TreeNode* traversal(vector<int>& nums, int left, int right)
    {
        // 2.递归终止条件：区间无效
        if(right <= left)  
            return nullptr;
        else if(right - left == 1)   // 区间只有一个数，就是叶子节点
        {
            TreeNode *leaf = new TreeNode(nums[left]);
            return leaf;
        }
        
        // 3.开始递归
        int middle = left + (right - left) / 2;
        TreeNode* cur = new TreeNode(nums[middle]);  // 构造当前节点
        // 使用[left, right)把左右子数组传入递归函数，构造左右子树，作为当前节点的左右孩子
        cur->left = traversal(nums, left, middle);  
        cur->right = traversal(nums, middle+1, right);

        // 递归结束，返货构造的根节点
        return cur;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size());
    }
};