/**
 * @file 98.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * 验证一棵树是否是二叉搜索树
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

    // 注意一定要是引用传递
    void traversal(TreeNode* root, vector<int>& vec)
    {
        if(root == nullptr)
            return;
        // 中序遍历：左中右
        traversal(root->left, vec);
        vec.push_back(root->val);
        traversal(root->right, vec);
    }
    bool isValidBST(TreeNode *root)
    {
        vector<int> vec;
        traversal(root, vec);
        if(vec.size() == 1)
            return true;
        for(int i = 0; i < vec.size()-1; i++)
            if(vec[i] >= vec[i+1])  // 注意等于也不行，必须严格递增
                return false;
        return true;
    }

    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode *root)
    {
        // 2.递归终止条件
        if(root == nullptr)
            return true;
        // 3.递归，左中右
        bool left = isValidBST(root->left);
        if(pre != nullptr && pre->val >= root->val)  // 前一个节点的值>=当前节点，不满足，直接返回
            return false;
        pre = root;   // 更新前一个节点
        bool right = isValidBST(root->right);
        return left && right;
    }
};