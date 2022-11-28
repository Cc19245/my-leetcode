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

        TreeNode(int val_) : val(val_) {}
    };

    
    vector<int> vec;

    // 左中右顺序收集二叉搜索树的所有数字，得到升序的数组
    void traversal(TreeNode* root)
    {
        if(root == nullptr)
            return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }

    // 传入升序数组和左右边界（左闭右闭），构造平衡二叉搜索树
    TreeNode* buildTree(const vector<int>& nums, int left, int right)
    {
        if(left > right)
            return nullptr;
        
        int middle = left + (right - left) / 2;
        TreeNode* cur = new TreeNode(nums[middle]);
        cur->left = buildTree(nums, left, middle-1);
        cur->right = buildTree(nums, middle+1, right);

        return cur;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        traversal(root);   // 先收集结果
        return buildTree(vec, 0, vec.size()-1);  // 然后构造二叉搜索树
    }
};