/**
 * @file 637.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 层序遍历二叉树，求每一层的平均值
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

    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode*> que;
        if(root == nullptr)
            return res;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            long sum = 0;
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                sum += cur->val;
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
            res.push_back((double)sum/size); 
        }
        return res;
    }
};