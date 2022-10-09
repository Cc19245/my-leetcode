/**
 * @file 654.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * 给定一个数组，构造最大二叉树。最大二叉树的定义见力扣上的题目内容
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
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        // 2.终止条件：传入的数组只有一个值，说明到了叶子节点
        if(nums.size() == 1)
        {
            TreeNode* leaf = new TreeNode(nums[0]);
            return leaf;
        }

        // 3.递归
        int max_val = INT32_MIN;
        int index = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max_val)
            {
                max_val = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(nums[index]);
        // 分割左右子树的数组，[ , )区间
        vector<int> left(nums.begin(), nums.begin() + index); 
        vector<int> right(nums.begin() + index + 1, nums.end());
        if(left.size())   // 左子树中有元素才构造，如果是0个元素，那么没有必要构造了
            root->left = constructMaximumBinaryTree(left);
        if(right.size())
            root->right = constructMaximumBinaryTree(right);

        // 最后，所有迭代都完成， 返回构造的根节点
        return root;
    }

    // 优化，避免每次都新建vector
    TreeNode* traversal(vector<int>& nums, int begin, int end)
    {
        // 2.递归终止条件：传入长度为1的数组，就是叶子节点
        if(end - begin == 1)
        {
            TreeNode* leaf = new TreeNode(nums[begin]);
            return leaf;
        }

        // 3.递归
        int max_val = INT32_MIN;
        int index = 0;
        for(int i = begin; i < end; i++)
        {
            if(nums[i] > max_val)
            {
                max_val = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(max_val);
        // 分割左右子树的区间
        int left_begin = begin;
        int left_end = index;
        int right_begin = index + 1;
        int right_end = end;
        if(left_end - left_begin > 0)
            root->left = traversal(nums, left_begin, left_end);
        if(right_end - right_begin > 0)
            root->right = traversal(nums, right_begin, right_end);
        
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size());
    }

};