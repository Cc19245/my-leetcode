/**
 * @file 112.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-08
 * 
 * 判断二叉树从根节点到叶子节点中，是否存在一条路径，其节点之和等于目标值
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>

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
    
    bool traversal(TreeNode* root, int count)
    {
        // 2.终止条件：到了子节点，判断count == 0?
        if(root->left == nullptr && root->right == nullptr)
        {
            if(count == 0) 
                return true;
            else
                return false;
        }

        // 3.递归
        if(root->left)
        {
            count -= root->left->val;   // 在进入子节点的递归函数之前， 就要把保证已经把子节点的数值减掉了
            // 如果遍历子节点结果是true，那么立刻就层层往上返回，不用再遍历了
            if(traversal(root->left, count))  
                return true;
            count += root->left->val;   // 回溯，再次回到当前节点，所以把遍历子节点之前减去子节点的值再加回来
        }
        if(root->right)
        {
            count -= root->right->val;   // 在进入子节点的递归函数之前， 就要把保证已经把子节点的数值减掉了
            // 如果遍历子节点结果是true，那么立刻就层层往上返回，不用再遍历了
            if(traversal(root->right, count))  
                return true;
            count += root->right->val;   // 回溯，再次回到当前节点，所以把遍历子节点之前减去子节点的值再加回来
        }

        // 其实根本不会运行到这里，但是不写的话力扣可能会报错没有返回值，所以还是写上吧
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if(root == nullptr)
            return false;
        // 同理这里注意，在调用递归函数遍历根节点的时候，一定要保证已经把根节点的数值减掉了
        return traversal(root, targetSum - root->val);
    }
};