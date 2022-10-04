/**
 * @file 94.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-04
 * 
 * 二叉树的中序遍历，左中右
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        // 注意这里为什么是这两个判断条件，并且中间是||？还是不太明白
        while(cur != nullptr || !st.empty())
        {
            // 1.先遍历所有节点指针，一直遍历到最下面的左节点
            if(cur != nullptr)
            {
                st.push(cur);      // 存储当前遍历过的节点
                cur = cur->left;   // 更新下一个节点，左
            }
            // 2.开始回溯，处理元素：注意回溯过程中会按照左中右的顺序把右边元素也加到栈中
            else
            {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);    // 中
                cur = cur->right;          // 右 
            }
        }

        return res;
    }

};