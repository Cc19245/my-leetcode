/**
 * @file 235.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * 给一个二叉搜索树，找到该树中两个指定节点的最近公共祖先
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


    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 2.递归终止条件：实际上本文不会使用
        if(root == nullptr)
            return nullptr;
        
        // 3.递归
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        // 运行到这里，说明是找到了最小公共祖先，那么层层向上返回
        return root;
    }
};