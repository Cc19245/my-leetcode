/**
 * @file 235.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * 给一个二叉搜索树，插入指定节点
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


    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 2.递归终止条件：找到null，就是插入的位置
        if(root == nullptr)
        {
            TreeNode* cur = new TreeNode(val);
            return cur;
        }

        // 3.开始递归
        if(val < root->val)
            // 把生成的节点返回给调用的根节点，因为生成的节点就是根节点的孩子
            root->left = insertIntoBST(root->left, val);
        else if(val > root->val)
            root->right =  insertIntoBST(root->right, val);
        
        return root;
    }
};