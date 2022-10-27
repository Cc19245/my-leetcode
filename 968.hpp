#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
    };
    
    int result;   // 最终添加的摄像头数量
    int traversal(TreeNode* root)
    {
        // 0是无覆盖，1是有摄像头，2是有覆盖
        if(root == nullptr)
            return 2;
        
        int left = traversal(root->left);
        int right = traversal(root->right);

        // 1.左右都有覆盖，当前位置不需要加摄像头，且下一个摄像头应该加载当前节点的父节点上
        //   因此当前节点应该设置为无覆盖
        if(left == 2 && right == 2)
        {
            return 0;
        }   
        // 2.左右节点只要有一个无覆盖，那么当前节点必须加一个摄像头，才能把子节点覆盖上
        else if(left == 0 || right == 0)
        {
            result++;
            return 1;
        }
        // 3.左右节点只要有一个有摄像头，则就可以覆盖当前父节点，所以设置当前节点为已覆盖
        else if(left == 1 || right == 1)
        {
            return 2;
        }
        
        // 实际不会运行到这里
        return -1;  
    }

public:

    int minCameraCover(TreeNode *root)
    {
        result = 0;

        // 情况4：遍历完之后，根节点还没有覆盖，则在根节点上加一个摄像头
        if(traversal(root) == 0)
            result++;

        return result; 
    }
};