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

    ListNode *detectCycle(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            // 先走
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)  // 找到环了
            {
                ListNode* new_slow = head;
                while(new_slow != slow)
                {
                    new_slow = new_slow->next;
                    slow = slow->next;
                }
                return new_slow;
            }
        }

        return nullptr;
    }
};