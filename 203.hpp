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
        ListNode(int val, ListNode* next) : val(val), next(next){}
    };
    
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode* dummy = new ListNode(0, head);   // 先指定一个虚拟头head
        ListNode* cur = dummy;
        while(cur->next != nullptr)
        {
            if(cur->next->val == val)  // 下一个节点是要删除的节点
            {
                ListNode* tmp = cur->next;  // 要删除的节点
                cur->next = cur->next->next;
                delete tmp;   // 真正删除
            }
            else  // 注意只有不删除的时候再遍历下一个，因为如果删除了，那么还有通过当前节点判断新的下一个节点是否删除，所以cur不能变
            {
                cur = cur->next;  // 遍历到下一个节点
            } 
        }
        head = dummy->next;
        delete dummy;

        return head;
    }
};