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
        ListNode* next;
        ListNode(int val) : val(val), next(nullptr){}
    };
    
    ListNode *swapPairs(ListNode *head)
    {
        ListNode* dummy_node = new ListNode(0);
        dummy_node->next = head;
        ListNode* cur = dummy_node;

        // 0 1 2 3 4
        while(cur->next && cur->next->next)
        {
            ListNode* tmp1 = cur->next;   // 1
            ListNode* tmp3 = cur->next->next->next;  // 3
            cur->next = cur->next->next;  // 0 -> 2
            cur->next->next = tmp1;       // 2 -> 1
            cur->next->next->next = tmp3; // 1 -> 3
            cur = cur->next->next;   // 更新到1的位置
        }
        
        return dummy_node->next;
    }
};