/**
 * @file 530.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * 给一个有重复元素的二叉搜索树，求其中的所有众数（即重复出现的元素）
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
        TreeNode *left;
        TreeNode *right;
    };


    TreeNode* pre = nullptr;   // 前一个节点
    int count = 0;       // 当前数字出现的次数
    int max_count = 0;   // 众数出现的最大次数
    vector<int> result;
    void traversal(TreeNode *root)
    {
        // 2.终止条件
        if (root == nullptr)
            return;
        // 3.开始递归
        traversal(root->left);
        
        // 3.1.判断中间节点是不是一个新的数，并统计出现次数
        if(pre == nullptr)   // 如果是遍历的第一个节点，则当前这个数出现次数为1
            count = 1;      
        else if(pre->val == root->val)  // 如果这个数重复出现，累加它出现的次数
            count++;
        else     // 如果这是一个新的数，那么新的数出现次数初始化成1
            count = 1;
        pre = root;    // 更新其哪一个节点的备份

        // 3.2.根据出现次数判断是不是众数
        if(count == max_count)   // 多个众数
            result.push_back(root->val);
        else if(count > max_count)   // 之前的众数都是假的，清空，加入新的众数
        {
            max_count = count;   // 更新最大频率
            result.clear();      // 把之前存储的假的众数清空
            result.push_back(root->val);   // 把最新的真的众数加进来
        }
    
        traversal(root->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        traversal(root);
        return result;
    }
};