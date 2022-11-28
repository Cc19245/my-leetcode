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

    int result;  // 最终累加的结果
    vector<int> path;   // 收集中间路径的值

    // 把path中的数字转成int
    int vectorToInt(const vector<int>& path)
    {
        int sum = 0;
        for(const auto& num : path)
            sum = 10 * sum + num;
        return sum;
    }

    void traversal(TreeNode* root)
    {
        // 2.递归终止条件：到达叶子节点，则开始收集结果
        if(root->left == nullptr && root->right == nullptr)
        {
            result += vectorToInt(path);  // 收集结果
            return;   // 直接返回
        }

        // 3.开始递归
        if(root->left)
        {
            path.push_back(root->left->val);  // 递归之前先把当前的节点的数字加到数组中
            traversal(root->left);   // 递归
            path.pop_back();  // 回溯
        }

        if(root->right)
        {
            path.push_back(root->right->val);
            traversal(root->right);
            path.pop_back();  // 回溯
        }
    }

    int sumNumbers(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        path.push_back(root->val);  // 先把根节点存到路径中
        traversal(root);  // 然后调用递归
        return result;  // 最后返回结果
    }
};