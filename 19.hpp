/**
 * @file 19.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * 删除链表中的倒数第n个节点，返回链表的头指针
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

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

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* dummy_node = new ListNode(0, head);

        ListNode* fast = dummy_node;
        ListNode* slow = dummy_node;
        while(n-- && fast->next != nullptr)
        {
            fast = fast->next;
        }
        // 至此fast->next就是第n个节点
        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 至此fast指向最后一个节点，slow的下一个节点就是倒数第n个节点，就是要被删除的节点

        ListNode* tmp = slow->next;   
        // 这里修改了next箭头的指向，因此上面要备份原来的next箭头指向的节点
        slow->next = slow->next->next;
        delete tmp;

        return dummy_node->next;
    }
};