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
        ListNode *next;
        ListNode(int val, ListNode *next) : val(val), next(next) {}
    };

    ListNode *reverseList(ListNode *head)
    {
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};