/**
 * @file 144.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-04
 * 
 * 二叉树的前序遍历，中左右
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right){}
    };

#if 0    
    // 递归法实现
    void traversal(TreeNode* root, vector<int>& val)
    {
        if(root == nullptr)
            return;
        val.push_back(root->val);   // 中
        traversal(root->left, val); // 左
        traversal(root->right, val); // 右
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
#endif

    // 迭代法实现（用栈）
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* mid = st.top();
            st.pop();
            res.push_back(mid->val);
            if(mid->right)
                st.push(mid->right);
            if(mid->left)
                st.push(mid->left);
        }

        return res;
    }

};