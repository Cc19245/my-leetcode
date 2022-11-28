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

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // 左右都是空，则相同
        if(p == nullptr && q == nullptr)
            return true;
        else if(p == nullptr && q != nullptr)
            return false;
        else if(p != nullptr && q == nullptr)
            return false;
        else  // 左右都不是空，然后就要比较数值，数值不同则直接false
            if(p->val != q->val)
                return false;

        // 运行到这里，则当前节点不为空，并且数值相同，则需要往下递归
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;  // 返回当前节点的结果
    }
};