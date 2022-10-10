/**
 * @file 530.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * 给一个二叉搜索树，求其中任意两个节点之间的最小差值
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
    
    void traversal(TreeNode* root, vector<int>& nums)
    {
        // 2.终止条件
        if(root == nullptr)
            return;
        // 3.开始递归
        traversal(root->left, nums);
        nums.push_back(root->val);
        traversal(root->right, nums);
    }

    int getMinimumDifference(TreeNode *root)
    {
        vector<int> nums;
        traversal(root, nums);
        // 如果只有0个或1个数，那么差值就是0
        if(nums.size() < 2)
            return 0;
        int res = INT32_MAX;
        for(int i = 0; i < nums.size() - 1; i++)
            // 注意这里已经是升序数组了，所以求绝对值就用后边减前边即可
            res = res < (nums[i+1] - nums[i]) ? res : (nums[i+1] - nums[i]);
        return res;
    }

    // 改进，在遍历的过程中就计算最小差值
    int result = INT32_MAX;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* root)
    {
        // 2.迭代终止条件
        if(root == nullptr)
            return;
        // 3.递归
        traversal(root->left);
        if(pre != nullptr)
            // 注意中序遍历过程中遍历的节点顺序就是从小到达的，所以当当前(root)值一定比之前的(pre)的值大
            result = result < (root->val - pre->val) ? result : (root->val - pre->val);
        pre = root;   // 便利完当前节点，备份前一个节点
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);
        return result;
    }
};