#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val, ListNode* next) : val(val), next(next) {}
    };

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 还是用虚拟头节点更好
        ListNode* dummy_node = new ListNode(0, head);
        ListNode* fast = dummy_node;
        ListNode* slow = dummy_node;

        while(n--)
            fast = fast->next;
        
        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        return head;
    }
};