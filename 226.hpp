/**
 * @file 226.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 翻转二叉树
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

    // 递归法
    TreeNode* invertTree(TreeNode* root) 
    {
        // 1.迭代终止条件
        if(root == nullptr)
            return root;
        
        // 2.处理当前节点，交换它的左右子节点
        swap(root->left, root->right);
        
        // 3.递归，处理子节点
        invertTree(root->left);
        invertTree(root->right);

        // 最后这个return是返回整个求解问题的结果，也就是整个树的根节点
        return root;
    }
};