/**
 * @file 0207.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
        ListNode(int x) : val(x), next(nullptr) {}
    };


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len_a = 0;
        int len_b = 0;
        ListNode* cur_a = headA;
        ListNode* cur_b = headB;

        // 查询AB两个链表的总长度
        while(cur_a != nullptr)
        {
            len_a++;
            cur_a = cur_a->next;
        }
        while(cur_b != nullptr)
        {
            len_b++;
            cur_b = cur_b->next;
        }

        // 把两个指针恢复到头指针
        cur_a = headA;
        cur_b = headB;

        int offset = len_a - len_b;
        if(offset > 0)
        {
            while(offset--)
            {
                cur_a = cur_a->next;
            }
        }
        else
        {
            offset = -offset;
            while(offset--)
            {
                cur_b = cur_b->next;
            }
        }

        while(cur_a != nullptr)
        {
            if(cur_a == cur_b)
            {
                return cur_b;
            }
            else
            {
                cur_a = cur_a->next;
                cur_b = cur_b->next;
            }
        }

        return nullptr;
    }
};