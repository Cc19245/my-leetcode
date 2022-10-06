/**
 * @file 222.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 统计完全二叉树的节点个数
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

    int countNodes(TreeNode* root) 
    {
        int res = 0;
        queue<TreeNode*> que;
        if(root == nullptr)
            return res;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();   // 当前要遍历的这一层的节点个数
            // 遍历这一层的所有节点
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                res++;
                // 把这个节点的子节点（即下一层）加到队列中，为下一次遍历做准备
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
        }
        
        return res;
    }

#if 1
    // 使用递归算法
    int countNodes(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;
        int left_num = countNodes(root->left);    // 左子树节点数量
        int right_num = countNodes(root->right);  // 右子树节点数量
        return (left_num + right_num + 1);      // +1是把当前root节点也算上
    }

    // 使用递归算法，同时利用完全二叉树的性质，如果是满二叉树直接用公式计算节点数量
    int countNodes(TreeNode* root) 
    {
        // 2.1.递归终止条件1：遍历到最后
        if(root == nullptr)
            return 0;
        // 2.2.递归终止条件2：以root为根节点的子树是一颗满二叉树
        //     一直遍历左边，计算左边的深度。注意是从0开始的，即2层的深度，结果是1
        TreeNode* left = root->left;
        int left_depth = 0;
        while(left != nullptr)
        {
            left = left->left;
            left_depth++;
        }
        //     一直遍历右边边，计算右边的深度。注意是从0开始的，即2层的深度，结果是1
        TreeNode* right = root->right;
        int right_depth = 0;
        while(right != nullptr)
        {
            right = right->right;
            right_depth++;
        }
        if(left_depth == right_depth)
        // 注意这里2层的话，left_depth=1，2<<1=4，结果恰好是对的
            return (2 << left_depth) - 1;  

        // 3.递归逻辑
        int left_num = countNodes(root->left);    // 左子树节点数量
        int right_num = countNodes(root->right);  // 右子树节点数量
        return (left_num + right_num + 1);      // +1是把当前root节点也算上
    }
#endif
};