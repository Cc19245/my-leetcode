/**
 * @file 142.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * 寻找环形链表的第一个入环节点
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode *detectCycle(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        // 注意这里只判断到fast->next即可，不需要判断到fast->next->next
        while(fast != nullptr && fast->next != nullptr)
        {
            // 这里一定要先移动再判断，而不能上来就判断是否相等，因为一开始他俩都是head，肯定是相等的
            fast = fast->next->next;
            slow = slow->next;
            // 找到了环的入口点
            if(fast == slow)
            {
                // 让一个新的指针从head出发，然后每次走一步，最终会和slow指针在环的入口点相遇
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
