/**
 * @file 450.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * 给一个二叉搜索树，给一个删除值，返回删除掉这个节点之后的二叉搜索树
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


    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 2.递归终止条件
        if(root == nullptr)
            return nullptr;   // 没找到要删除的节点
        if(root->val == key)  // 找到了要删除的节点
        {
            if(!root->left && ! root->right)   // 叶子节点
                // 这里因为删除叶子节点的时候，是通过调用它的根节点进行删除的，所以删除之后的结果
                // 也要返回给它的根节点的左/右孩子，这里通过赋值nullptr实现删除操作
                return nullptr;    
            else if(root->left && !root->right)  // 左非空，右空，直接返回左孩子
                return root->left;
            else if (!root->left && root->right)
                return root->right;
            else   // 左右都不是空
            {
                TreeNode* cur = root->right;   // 寻找右子树中值最小的那个节点
                while(cur->left)
                    cur = cur->left;
                cur->left = root->left;  // root的左子树，赋值给root右子树的最小节点的左子树
                return root->right;      // 把root删掉，返回它的右孩子给上一层
            }
        }

        // 3.开始递归调用
        if(key < root->val)
            // 从当前节点的左子树中删除目标节点，删除后的子树根节点返回，作为当前节点的左孩子
            root->left = deleteNode(root->left, key);  
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        
        return root;   // 当前子树的左/右子树中删除了目标节点，返回当前树
    }
};