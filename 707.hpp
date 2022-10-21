#pragma once
#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val, ListNode *next) : val(val), next(next) {}
    };

private:
    int size;
    ListNode *dummy_node;

public:
    MyLinkedList()  // 这个构造函数就是初始化成员变量，没有别的。真正节点添加要靠下面的函数
    {
        size = 0;
        dummy_node = new ListNode(0, nullptr);   
    }

    int get(int index)
    {
        if (index < 0 || index > size - 1)
            return -1;

        ListNode* cur = dummy_node;
        while(index--)
        {
            cur = cur->next;
        }
        return cur->next->val;
    }

    void addAtHead(int val)
    {
        ListNode* node = new ListNode(val, nullptr);
        node->next = dummy_node->next;
        dummy_node->next = node;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode* cur = dummy_node;
        while(cur->next != nullptr)
            cur = cur->next;
        ListNode* node = new ListNode(val, nullptr);
        cur->next = node;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if(index < 0)
        {
            addAtHead(val);
            return;
        }
        if(index > size)
            return;
        
        ListNode* cur = dummy_node;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode* node = new ListNode(val, nullptr);
        node->next = cur->next;
        cur->next = node;
        
        size++;
    }

    void deleteAtIndex(int index)
    {
        if(index < 0 || index > size - 1)  
            return;
        
        ListNode* cur = dummy_node;
        while(index--)
            cur = cur->next;
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }
};