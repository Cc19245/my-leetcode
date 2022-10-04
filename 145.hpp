/**
 * @file 145.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-04
 * 
 * 二叉树的后序遍历，左右中
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

    // 迭代法实现（用栈）
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> st;
        if(root == nullptr)
            return res;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            // 中右左
            res.push_back(cur->val);   // 中
            if(cur->left)
                st.push(cur->left);
            if(cur->right)
                st.push(cur->right);
        }
        reverse(res.begin(), res.end());

        return res;
    }

};