/**
 * @file 429.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * N叉树，给出层序遍历结果
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;  // n叉树

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        queue<Node*> que;
        if(root == nullptr)
            return res;
        que.push(root);
        while(!que.empty()) 
        {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++)
            {
                Node* cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                vector<Node*> children = cur->children;
                for(auto child : children)
                {
                    if(child != nullptr)
                        que.push(child);
                }
            }
            res.push_back(vec);
        }

        return res;
    }
};