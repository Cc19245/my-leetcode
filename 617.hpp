/**
 * @file 617.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * 合并两棵二叉树
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
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // 2.递归终止条件：有一个节点是null，那么直接返回另外一个节点（一个子树）
        if(root1 == nullptr)
            return root2;
        if(root2 == nullptr)
            return root1;

        // 3.递归
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }

};