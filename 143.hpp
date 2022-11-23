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

    // 1.解法一：使用数组存储ListNode，然后使用首尾双指针来修改list的指向
    void reorderList(ListNode *head)
    {
        if(head == nullptr)
            return;
        
        // 1.存储节点
        vector<ListNode*> vec;
        ListNode* cur = head;
        // 注意这里不需要存头结点，因为头结点位置是不动的
        while(cur->next != nullptr)
        {
            vec.push_back(cur->next);   
            cur = cur->next;
        }

        // 2.前后双指针重构链表
        cur = head;  // 头节点，不动
        int left = 0;   // 指向vec中节点的左指针
        int right = vec.size() - 1;  // 指向vec中节点的右指针
        int count = 0;   // 表示当前该存储左指针还是右指针
        while(left <= right)
        {
            if(count % 2 == 0)   // 存储右指针
                cur->next = vec[right--];
            else    // 存储左指针
                cur->next = vec[left++];
            cur = cur->next;  // 移动到下一个位置，修改下个节点的指向
            count++;
        }

        // 3.最后一个节点指向nullptr
        cur->next = nullptr;   
    }

    // 2.解法二：使用双向队列存储，这样就可以首尾弹出，不用使用双指针了
    void reorderList(ListNode *head)
    {
        if(head == nullptr)
            return;
        
        // 1.存储节点
        deque<ListNode*> que;
        ListNode* cur = head;
        // 注意这里不需要存头结点，因为头结点位置是不动的
        while(cur->next != nullptr)
        {
            que.push_back(cur->next);   
            cur = cur->next;
        }

        // 2.使用deque前后访问节点，每访问一个节点之后就把它弹出
        cur = head;  // 头节点，不动
        int count = 0;   // 表示当前该存储左指针还是右指针
        while(!que.empty())
        {
            if(count % 2 == 0)   // 存储右指针
            {
                cur->next = que.back();
                que.pop_back();
            }
            else    // 存储左指针
            {
                cur->next = que.front();
                que.pop_front();
            }
            count++;
            cur = cur->next;
        }

        // 3.最后一个节点指向nullptr
        cur->next = nullptr;   
    }


     // 3.解法三：拆分链表，把链表分成前后两部分，然后把后半部分翻转，然后依次
    void reorderList(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return;
        
        // 1.快慢指针来拆分链表
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2.至此，pre是前一个链表的结尾，slow是后一个链表的开头
        // 注意cur2可能和cur1长度相等，也可能比cur1长度大1
        ListNode* cur1 = head->next;
        pre->next = nullptr;   // 把前一个链表的尾巴截断，方便后面遍历
        ListNode* cur2 = reverseList(slow);   // 后一个链表翻转

        // 3.遍历开始重构链表
        int count = 0;
        ListNode* cur = head;
        while(cur2)
        {
            if(count % 2 == 0)  // 偶数
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                cur->next = cur1;
                cur1 = cur1->next; 
            }
            cur = cur->next;
            count++;
        }
        cur->next = nullptr;   // 最后一个位置
    }

    // 翻转链表
    ListNode* reverseList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};