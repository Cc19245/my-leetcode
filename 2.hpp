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

        ListNode(int val_) : val(val_), next(nullptr) {}
    };

    // 注意已经说的了l1/l2都不是空
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 使用虚拟头结点，方便处理
        ListNode* dummy = new ListNode(-1);   
        ListNode* cur = dummy;  
        int add = 0;   // 前一个节点相加是否有进位，如果有就是1，没有就是0

        // 开始逐个节点相加
        while(l1 || l2)
        {
            int val = 0;
            if(l1)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                val += l2->val;
                l2 = l2->next;
            }
            val += add;   // 加上上次进位的值
            cur->next = new ListNode(val % 10);  // 使用虚拟头节点，这里通过next来新建下一个节点
            add = val / 10;   // 本次进位结果
            cur = cur->next;  // 更新数组位置
        }
        
        // 最后一次相加的结果可能还有进位，但是被l1 || l2的判断条件忽略了，所以还要判断最后一次
        if(add)
            cur->next = new ListNode(1);  // 最后一个节点
        
        return dummy->next;   // 返回头节点
    }
};