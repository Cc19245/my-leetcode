/**
 * @file 110.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 判断一棵二叉树是否是平衡二叉树
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <queue>
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
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int getHeight(TreeNode* root)
    {
        // 2.迭代终止条件
        if(root == nullptr) 
            return 0;
        
        // 3.开始迭代
        int left_height = getHeight(root->left);
        // 左子树已经不是平衡二叉树了，那么以root为根的树也不是平衡二叉树，所以直接返回
        if(left_height == -1)
            return -1;   
        int right_height = getHeight(root->right);
        if(right_height == -1)
            return -1;
        int result = 0;
        if(abs(left_height - right_height) > 1)   // 高度差>1，不是平衡二叉树
            result = -1;
        else 
            result = 1 + max(left_height, right_height);
        
        return result;
    }

    bool isBalanced(TreeNode *root)
    {
        // 求根节点高度，如果不是-1，那么就是平衡二叉树
        return (getHeight(root) != -1);
    }
};