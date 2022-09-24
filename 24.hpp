/**
 * @file 24.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * 两两交换链表中的节点，比如[1, 2, 3, 4]交换后变成[2, 1, 4, 3]
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr){}
        ListNode(int x, ListNode* ptr): val(x), next(ptr){}
    };

    ListNode *swapPairs(ListNode *head)
    {
        ListNode* dummy_node = new ListNode(0);
        dummy_node->next = head;
        // 链表举例： [cur, 1, 2, 3, 4]
        // 索引位置： [cur, 1, 2, 3, 4]
        ListNode* cur = dummy_node;  // 从虚拟头节点0开始
        // 要交换的是第1和2个节点，因此他们不能是空
        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            // 关于要备份哪些节点，实际上可以先编程后面，发现哪里缺了再在这里备份
            ListNode* tmp1 = cur->next;
            ListNode* tmp3 = cur->next->next->next;

            // 步骤1：cur的箭头指向第2个节点，由于cur的箭头被修改，因此需要备份它原来箭头指向的节点，即tmp1
            cur->next = cur->next->next;
            // 步骤2：第2个节点的箭头指向第1个节点，由于第2个节点的箭头被修改，因此要备份它原来箭头指向的节点，即tmp3
            cur->next->next = tmp1;
            // 步骤3：第1个节点的箭头指向第3个节点
            cur->next->next->next = tmp3;

            cur = cur->next->next;   // 最后，cur跳两个位置，交换下两个节点
        }
        return dummy_node->next;  // 返回交换后的链表的头指针
    }
};