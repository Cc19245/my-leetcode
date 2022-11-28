/**
 * @file 116.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * 层序遍历二叉树，填充每一层右侧的节点
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> que;
        if (root == nullptr)
            return root;
        que.push(root);

        while (!que.empty())
        {
            int size = que.size(); // 当前要遍历的这一层的节点个数
            // 遍历这一层的所有节点
            for (int i = 0; i < size; i++)
            {
                Node *cur = que.front();
                que.pop();
                if(i < size - 1)
                    cur->next = que.front();
                else
                    cur->next = nullptr;
                // 把这个节点的子节点（即下一层）加到队列中，为下一次遍历做准备
                if (cur->left != nullptr)
                    que.push(cur->left);
                if (cur->right != nullptr)
                    que.push(cur->right);
            }
        }

        return root;
    }

    void traversal(Node* root)
    {
        if(root == nullptr)
            return;
        // 中
        if(root->left)   
            root->left->next = root->right;  // 注意完美二叉树，所以左不为空的话，右一定也不为空
        if(root->right)  
        {
            if(root->next)  // 上一层有连接线的话，就可以给本层的连接线提供桥梁
                root->right->next = root->next->left;
            else
                root->right->next = nullptr;
        }

        // 左右
        traversal(root->left);
        traversal(root->right);
    }

    Node *connect(Node *root)
    {
        traversal(root);
        return root;
    }
};