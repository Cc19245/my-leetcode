/**
 * @file 513.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-08
 * 
 * 给定一个二叉树，寻找最下面一层、最左边的值
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <queue>

using namespace std;


class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
        /* data */
    };
    
    // 迭代法层序遍历
    int findBottomLeftValue(TreeNode *root)
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
                if(i == 0)
                    res = cur->val;
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
        }
        return res;
    }

    // 递归法前中后序遍历
    int max_depth = INT32_MIN;
    int res = 0;
    void traversal(TreeNode* root, int depth)
    {
        // 2.迭代终止条件：如果到达叶子节点，判断深度是否比上一次的大
        if(root->left == nullptr && root->right == nullptr)
        {
            if(depth > max_depth)
            {
                max_depth = depth;
                res = root->val;
            }
        }

        // 3.递归
        if(root->left != nullptr)
        {
            depth++;   // 开始递归了，遍历到下一层了，所以深度+1
            traversal(root->left, depth);
            depth--;   // 上面递归调用结束，到这里的时候就进行回溯了，所以depth--
        }
        if(root->right != nullptr)
        {
            depth++;   // 开始递归了，遍历到下一层了，所以深度+1
            traversal(root->right, depth);
            depth--;   // 上面递归调用结束，到这里的时候就进行回溯了，所以depth--
        }

        // 疑问：这里要不要return？应该用不用都可以吧？
    }

    int findBottomLeftValue(TreeNode *root)
    {
        if(root == nullptr)
            return res;
        traversal(root, 0);   // 遍历root根节点的时候，深度层数是0
        return res;
    }

};