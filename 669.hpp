/**
 * @file 669.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * 修剪二叉搜索树，让所有节点数值都在指定区间内
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
    };

    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // 2.递归终止条件
        if(root == nullptr)
            return nullptr;
        
        // 3.递归
        // 3.1.当前节点值在区间左边，那么修剪当前节点的右子树，返回结果
        if(root->val < low)   
        {
            return trimBST(root->right, low, high);
        }
        // 3.2.当前节点值在区间右边，那么修剪当前节点的左子树，返回结果
        else if(root->val > high)
        {
            return trimBST(root->left, low, high);
        }
        // 3.3.当前节点值在区间内，那么递归，修剪它的左右子树，修剪后的结果返回给当前节点的左右孩子
        else
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }

        // 最后，把整棵树修建完毕，返回整个树的根节点
        return root;
    }
};