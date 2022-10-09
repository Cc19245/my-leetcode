/**
 * @file 700.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * 二叉搜索树
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

    TreeNode *searchBST(TreeNode *root, int val)
    {
        // 2.递归终止条件：搜到叶子节点下面的null了，说明没搜到；或者搜到了这个节点恰好是目标节点
        if(root == nullptr || root->val == val)
            return root;
        
        // 3.递归
        TreeNode* result = nullptr;
        if(val < root->val)   // 搜左子树
            result = searchBST(root->left, val);
        else
            result = searchBST(root->right, val);
        
        // 最终返回搜索结果
        return result;
    }
};