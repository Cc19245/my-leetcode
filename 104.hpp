/**
 * @file 104.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 层序遍历二叉树，返回最大深度
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

    int maxDepth(TreeNode* root) 
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

                // 把这个节点的子节点（即下一层）加到队列中，为下一次遍历做准备
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
            // 遍历完这一层
            res++;
        }
        
        return res;
    }
};