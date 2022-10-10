/**
 * @file 236.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * 给两个节点，找最小公共节点
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
        // 2.递归终止条件
        if(root == nullptr)
            return nullptr;
        if(root == p || root == q)
            return root;
        
        // 3.开始递归
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr)
            return root;
        else if(left != nullptr && right == nullptr)
            return left;
        else if(left == nullptr && right != nullptr)
            return right;
        else    
            return nullptr;
    }
};