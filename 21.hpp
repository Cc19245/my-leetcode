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

        ListNode(int val) : val(val), next(nullptr) {}
    };

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode* dummy = new ListNode(0);  // dummy虚拟头节点
        ListNode* cur = dummy;

        // 遍历list1和list2，都不能是空
        while(list1 && list2)
        {
            // 选择小的那个数，作为下一个节点
            if(list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }   

        // 到了这个地方之后，list1和list2中可能有非空的，那么就把剩下的再拼接到cur中
        // 如果list1和list2都是空，那么结果就是走else，cur->next也是空，也是符合要求的
        if(list1)
            cur->next = list1;
        else
            cur->next = list2;
        
        // 最后把拼接后的头节点取出来，并把dummy节点删掉
        ListNode* res = dummy->next;
        delete dummy;
        
        return res;
    }
};
