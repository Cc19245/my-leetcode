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

    int pre = 0;
    void traversal(TreeNode *root)
    {
        // 2.递归终止条件
        if(root == nullptr)
            return;
        
        // 3.开始递归，右中左的顺序
        traversal(root->right);
        root->val += pre;   // 累加前一个节点的值
        pre = root->val;    // 更新当前节点的值，给下一次递归累加使用
        traversal(root->left);

        return;
    }

    TreeNode *convertBST(TreeNode *root)
    {
        pre = 0;   // 把上一个节点的值初始化成0
        traversal(root);   // 递归累加整个树的每个节点的值
        return root;   // 把累加后的结果返回
    }

    // 使用前一个节点指针
    TreeNode* pre = nullptr;
    void traversal(TreeNode *root)
    {
        // 2.递归终止条件
        if(root == nullptr)
            return;
        
        // 3.开始递归，右中左的顺序
        traversal(root->right);
        if(pre != nullptr)
            root->val += pre->val;   // 累加前一个节点的值
        pre = root;    // 更新当前节点的值，给下一次递归累加使用
        traversal(root->left);

        return;
    }
};