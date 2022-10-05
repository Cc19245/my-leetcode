/**
 * @file 515.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 层序遍历二叉树，找出每层最大值
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

    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        queue<TreeNode*> que;
        if(root == nullptr)
            return res;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();   // 当前要遍历的这一层的节点个数
            int max = INT32_MIN;     // 注意 -INT32_Max != INT32_MIN
            // 遍历这一层的所有节点
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if(cur->val > max)
                    max = cur->val;
                // 把这个节点的子节点（即下一层）加到队列中，为下一次遍历做准备
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
            // 遍历完这一层，把这一层的结果加到res中
            res.push_back(max);
        }
        
        return res;
    }
};