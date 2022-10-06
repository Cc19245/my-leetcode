/**
 * @file 404.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 二叉树的所有左叶子之和
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>

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

    // 迭代解法
    int sumOfLeftLeaves(TreeNode *root)
    {
        int res = 0;
        if(root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                
                // 左节点不是空，加入que中进行下一次遍历
                if(cur->left != nullptr)
                {
                    que.push(cur->left);
                    // 此时左节点不是空，那么就判断左节点是不是叶子节点，如果是则加入res中
                    if(cur->left->left == nullptr && cur->left->right == nullptr)
                        res += cur->left->val;
                }
                // 右节点不是空，加入que中进行下一次遍历
                if(cur->right != nullptr)
                {
                    que.push(cur->right);
                }
            }
        }

        return res;
    }

    
    // 递归解法
    int sumOfLeftLeaves(TreeNode *root)
    {
        // 2.终止条件
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)   // 遇到叶子节点
            return 0;
        
        // 3.递归
        int left_val = sumOfLeftLeaves(root->left);   // 左
        if(root->left && !root->left->left && !root->left->right)
            left_val = root->left->val;

        int right_val = sumOfLeftLeaves(root->right);  // 右

        int result = left_val + right_val;   // 中
        return result;
    }
};