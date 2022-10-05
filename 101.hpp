/**
 * @file 101.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 判断二叉树是否是对称二叉树
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

    bool compare(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right != nullptr)
            return false;
        else if(left != nullptr && right == nullptr)
            return false;
        else if(left == nullptr && right == nullptr)
            return true;
        else if(left->val != right->val)
            return false;

        // 运行到这里，说明当前左右节点相等。但是这还不能判断以当前左右节点为根节点的两棵树相等，
        // 还要继续往下判断他们的子树。这其实就产生了递归的过程
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return (outside && inside);
    }
    bool isSymmetric(TreeNode *root)
    {
        if(root == nullptr)
            return true;
        return compare(root->left, root->right);
    }
};