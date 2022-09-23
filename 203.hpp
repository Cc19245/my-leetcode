/**
 * @file 203.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-23
 * 
 * 移除链表中的某个元素
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

// 先手写链表节点的数据结构
struct ListNode
{
    int val;        // 存储的数据结构
    ListNode *next; // 指向下一个链表的指针

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *ptr) : val(x), next(ptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 直接使用原来的链表进行操作
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 如果删除的val恰好是头指针，那么就把头指针往后移动一下，然后把头指针删掉
        // 注意这里是while而不是if，因为有可能链表前面的几个元素值恰好都是要删除的值，因此用while才能全删掉
        while(head != nullptr && head->val == val)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;   // 注意手动释放删除掉的节点的内存
        }

        // 如果不是头指针，那么就按照正常的操作来删除链表。这里注意判断要删除的元素的时候，和头指针的情况不同，
        // 某个链表节点B是否需要被删除，是根据指向它的上一个链表A的node->next->val来判断的，因为如果要删除B，需要
        // 把它上一个节点A的next指针指向B的下一个节点C，也就是此时是在修改A的next变量，所以要通过A来判断B是否要删除，
        // 如果删除再操作A
        ListNode* cur = head;
        // 注意这里为什么要判断cur->next != nullptr，因为下面的while循环主要就是判断当前节点的下一个节点是否要被删除
        // 因此除了判断cur和cur->next都需要!=nullptr。实际上，当cur是最后一个节点的时候，它后面没有节点了，自然也就
        // 没有需要再被删除的节点了（注意循环到当前节点的时候，当前节点一定是不需要删除的，因为如果需要被删除的话，那么
        // 运行到当前节点之前，当前节点就被删除了，因此要是这种情况实际上根本不会运行到当前节点）
        while(cur != nullptr && cur->next != nullptr)
        {
            if(cur->next->val == val)
            {
                ListNode* tmp = cur->next;   // 下一个节点就是要被删除的
                cur->next = cur->next->next;
                delete tmp;   // 注意手动释放删除掉的节点的内存
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;   // 最终返回删除之后的链表的头指针
    }
};



// 新建一个虚拟head，将这个虚拟head指向真正的链表，然后就不用考虑head的删除问题了，都像
// 链表中间的普通情况一样删除即可
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode* dummy_head = new ListNode(0);   // 新建一个虚拟的head
        dummy_head->next = head;
        ListNode* cur = dummy_head;

        // 注意这里判断cur != nullptr实际上是没有必要的，这个和上面分是否是head节点的情况不同
        // 因为上面对于head节点进行了单独的删除操作，这有可能导致删除之后链表就变成空链表了，所以
        // 在进行后面普通的删除操作时需要判断节点是否是空。而这里没有进行删除操作，因此cur一定不会是空
        while(cur != nullptr && cur->next != nullptr)
        {
            if(cur->next->val == val)
            {
                ListNode* tmp = cur->next;    // 下一个节点就是要被删除的
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummy_head->next;
        delete dummy_head;

        return head;
    }
};