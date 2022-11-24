#pragma once
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
    };

    bool hasCycle(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true; 
        }

        return false;
    }
};