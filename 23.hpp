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
        ListNode *next;

        ListNode(int val) : val(val), next(nullptr) {}
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int size = lists.size();  // 所有链表的个数
        ListNode* dummy = new ListNode(0);  // 新建结果链表，使用虚拟头指针
        ListNode* cur = dummy;

        while(true)
        {
            // 记录本次选择的最小节点的指针，和对应于vector中是哪条链表的节点
            ListNode* min_node = nullptr;
            int list_index = -1; 
            for(int i = 0; i < size; i++)
            {
                // 如果这条链表已经遍历到头了，那么不需要对比了
                if(lists[i] == nullptr)
                    continue;
                // 运行到这里，说明这条链表还没有遍历完
                // 如果是第一次寻找当前位置的最小节点，则赋值min_node和list_index
                // 否则不是第一次，则如果当前节点值更小，则更新min_node和list_index
                if(min_node == nullptr || lists[i]->val < min_node->val)
                {
                    min_node = lists[i];
                    list_index = i;
                }
            }

            // 如果当期位置没有找到最小节点，说明所有链表都遍历完毕了，则直接跳出while循环
            if(min_node == nullptr)
                break;
            
            // 运行到这里，说明当前位置找到了最小节点，则先赋值、再后移节点
            cur->next = min_node;   // 赋值当前节点的下一个位置
            cur = cur->next;   // 移动当前节点到下一个位置
            lists[list_index] = lists[list_index]->next;  // 移动链表中的节点
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
