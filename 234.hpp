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
    };

    bool isPalindrome(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)   
            return true;

        // 1.寻找分割链表的位置
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast && fast->next)
        {
            pre = slow;   // 先备份pre节点
            slow = slow->next;  // slow走一步
            fast = fast->next->next;
        }

        // 2.此时slow为后半部分链表的head, pre为前半部分链表的结尾
        pre->next = nullptr;    // 把前半部分链表切分出来，方便后面遍历
        ListNode* list1 = head;
        ListNode* list2 = reverseList(slow);   // 翻转后半部分链表
        
        // 3.以前半部分链表长度为基准，判断前后链表是否相等
        while(list1 != nullptr)
        {
            if(list1->val != list2->val)
                return false;
            list1 = list1->next;
            list2 = list2->next;
        }

        return true;
    }

    // 翻转链表
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};