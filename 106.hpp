/**
 * @file 106.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-08
 * 
 * 给定二叉树中序和后续遍历的数组，构造二叉树
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

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    // 注意一定要按照引用来传递
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 2.递归终止条件：数组中没有元素了，那么直接返回null
        if (postorder.empty())
            return nullptr;
        // 切割本次的结果
        int root_val = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(root_val);
        // 如果只剩一个值了，说明遍历到了叶子节点
        if (postorder.size() == 1)
            return root;

        // 3.递归：用中切割中序数组，得到左右子树
        int index = 0;
        for (; index < inorder.size(); index++)
            if (inorder[index] == root_val)
                break;
        // 切割中序数组，左闭右开
        vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
        vector<int> right_inorder(inorder.begin() + index + 1, inorder.end());
        // 切割后续数组，左闭右开
        vector<int> left_postorder(postorder.begin(), postorder.begin() + index);
        vector<int> right_postorder(postorder.begin() + index, postorder.end() - 1);

        // 递归
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root;
    }
    
    // 左闭右开区间
    TreeNode *traversla(vector<int> &preorder, int pre_begin, int pre_end, 
                        vector<int> &inorder,  int in_begin,  int in_end)
    {
        // [ , )，如果相等说明区间为空
        if(pre_begin == pre_end)
            return nullptr;
        
        int root_val = preorder[pre_begin];
        TreeNode* root = new TreeNode(root_val);
        if(pre_end - pre_begin == 1)   // 区间只有一个元素，到达叶子节点，直接返回
            return root;
        
        // 3.递归
        // 先用根节点切割中序数组
        int index = in_begin;
        for(; index < in_end; index++)
            if(inorder[index] == root_val)
                break;
        // 左右中序数组
        int left_in_begin = in_begin;
        int left_in_end = index;
        int right_in_begin = index + 1;
        int right_in_end = in_end;
        // 左右前序数组
        int left_pre_begin = pre_begin + 1;
        int left_pre_end = left_pre_begin + index - in_begin;
        int right_pre_begin = left_pre_begin + index - in_begin;
        int right_pre_end = pre_end;

        // 递归调用
        root->left = traversla(preorder, left_pre_begin, left_pre_end, inorder, left_in_begin, left_in_end);
        root->right = traversla(preorder, right_pre_begin, right_pre_end, inorder, right_in_begin, right_in_end);

        return root;

    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int pre_begin = 0;
        int pre_end = preorder.size();
        int in_begin = 0;
        int in_end = inorder.size();

        return traversla(preorder, pre_begin, pre_end, inorder, in_begin, in_end);
    }
};
