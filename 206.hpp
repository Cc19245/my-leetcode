/**
 * @file 206.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-23
 * 
 * 给定一个单项链表，翻转链表
 * 
 * @copyright Copyright (c) 2022
 * 
 */


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
        ListNode(int x, ListNode* ptr): val(x), next(ptr){}
    };
    
    ListNode *reverseList(ListNode *head)
    {
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(cur != nullptr)
        {
            ListNode* next = cur->next;   // 保存下一个节点的位置
            cur->next = pre;   // 翻转当前节点
            pre = cur;         // 更新之前的节点，指向当前节点
            cur = next;        // 更新当前节点，指向下一个节点
        }
        // 注意返回的是pre，不是cur，因为执行到最后pre指向最后一个节点，而cur指向最后节点的next，即nullptr
        return pre;   
    }
};