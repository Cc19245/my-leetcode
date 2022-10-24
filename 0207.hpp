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
        ListNode(int val, ListNode *next) : val(val), next(next) {}
    };

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* dummy_a = new ListNode(0, headA);
        ListNode* dummy_b = new ListNode(0, headB);
        ListNode* cur_a = dummy_a;
        ListNode* cur_b = dummy_b;
        int len_a = 0;
        int len_b = 0;

        while(cur_a->next)
        {
            len_a++;
            cur_a = cur_a->next;
        }
        while(cur_b->next)
        {
            len_b++;
            cur_b = cur_b->next;
        }
        int diff = len_a - len_b;
        cur_a = dummy_a;
        cur_b = dummy_b;

        if(diff > 0)
            while(diff--)
                cur_a = cur_a->next;
        else
            while(diff++)
                cur_b = cur_b->next;
        while(cur_a->next)
        {
            if(cur_a == cur_b)
                return cur_b;
            cur_a = cur_a->next;
            cur_b = cur_b->next;
        }

        
        
    }
};