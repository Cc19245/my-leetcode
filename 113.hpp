/**
 * @file 113.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-08
 * 
 * 判断二叉树从根节点到叶子节点中，找出路径中其节点之和等于目标值的所有路径
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
        TreeNode* left;
        TreeNode* right;
    };
    
    // 注意result和path一定要用引用的形式传入，否则就变成了值拷贝了
    void traversal(TreeNode* root, int count, vector<vector<int>>& result, vector<int>& path)
    {
        // 2.终止条件：遍历到叶子节点，不管是不是符合条件的路径，都要返回
        if(root->left == nullptr && root->right == nullptr)
        {
            if(count == 0)
                result.push_back(path); 
            return;
        }

        // 3.递归
        if(root->left)
        {
            count -= root->left->val;           // 首先把count值减掉子节点的值
            path.push_back(root->left->val);    // 再把子节点这个路径加入
            traversal(root->left, count, result, path);   // 迭代
            count += root->left->val;           // 回溯，把count值再加回来
            path.pop_back();                    // 回溯，把子节点的路径弹出
        }
        if(root->right)
        {
            count -= root->right->val;           // 首先把count值减掉子节点的值
            path.push_back(root->right->val);    // 再把子节点这个路径加入
            traversal(root->right, count, result, path);   // 迭代
            count += root->right->val;           // 回溯，把count值再加回来
            path.pop_back();                    // 回溯，把子节点的路径弹出
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> result;
        vector<int> path;
        if(root == nullptr)
            return result;
        
        // 同理，在调用traversal函数递归之前，就要实现处理根节点
        targetSum -= root->val;
        path.push_back(root->val); 
        traversal(root, targetSum, result, path);
        return result;  
    }
};