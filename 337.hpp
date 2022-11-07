/**
 * @file 198.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
    };

    // 递归偷取二叉树的每一个节点，返回值 <不偷的最大价值，偷的最大价值>
    vector<int> robTree(TreeNode *root)
    {
        // 2.递归终止条件：遇到叶子节点，则不管偷不偷结果都是0
        if (root == nullptr)
            return {0, 0};

        // 3.开始递归：左右中，后序遍历
        vector<int> left = robTree(root->left);   // 偷左子树的结果
        vector<int> right = robTree(root->right); // 偷右子树的结果
        // 不偷当前节点，则可以偷左右子树，从左右子树中寻找最大值并相加
        int val1 = max(left[0], left[1]) + max(right[0], right[1]);
        // 偷当前节点，则左右子树都不能偷了
        int val2 = root->val + left[0] + right[0];

        // 返回最终结果：<不偷当前节点的最大价值， 偷当前节点的最大价值>
        return {val1, val2};
    }

public:
    int rob(TreeNode *root)
    {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);   // 最终结果就是偷不偷根节点的最大价值
    }
};