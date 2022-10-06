/**
 * @file 257.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 给出任意顺序遍历二叉树的路径
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>

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

    // 注意path和result都是引用传递，因为在递归过程中我们要回溯，要处理之前的结果
    void traversal(TreeNode* root, vector<int>& path, vector<string>& result)
    {
        // 注意这里可以直接使用root，因为调用递归之前会判断root不是空
        path.push_back(root->val);
        // 2.终止条件：到达叶子节点，则一条完整路径收集到，把他加入result中
        if(root->left == nullptr && root->right == nullptr)
        {
            string this_path;
            for(int i = 0; i < path.size() - 1; i++)
            {
                this_path += to_string(path[i]);
                this_path += "->";
            }
            this_path += to_string(path[path.size()-1]);   // 最后一个字符
            result.push_back(this_path);   // 收集这次的结果
            return;     // 此次递归结束，返回
        }

        // 3.调用递归，一直递归到叶子节点
        if(root->left != nullptr)
        {
            traversal(root->left, path, result);
            path.pop_back();    // 上面的递归函数调用完成后，回溯，把最后一个元素弹出来
        }
        if(root->right != nullptr)
        {
            traversal(root->right, path, result);
            path.pop_back();    // 上面的递归函数调用完成后，回溯，把最后一个元素弹出来
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> result;
        traversal(root, path, result);
        return result;
    }
};