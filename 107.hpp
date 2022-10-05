/**
 * @file 107.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 层序遍历二叉树，从下网上
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <queue>
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

    // 正序遍历，然后把结果reverse即可
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root == nullptr)
            return res;
        que.push(root);

        while(!que.empty())
        {
            vector<int> vec;
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
            res.push_back(vec);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};