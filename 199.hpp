/**
 * @file 199.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 给二叉树，返回它的每一层最右边的值
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

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode*> que;
        if(root == nullptr)
            return res;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            int right;  // 最右边的节点的数值
            // 下面还是正常遍历这一层的所有节点，每次都更新right值，最后遍历的就是right的值
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();  
                right = cur->val;
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
           res.push_back(right);
        }

        return res;
    }
};