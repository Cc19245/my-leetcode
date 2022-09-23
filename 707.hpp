/**
 * @file 707.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-23
 * 
 * 设计链表，其中包括很多功能
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x, ListNode* ptr): val(x), next(ptr){}
    };
    
    MyLinkedList()
    {
        dummy_node_ = new ListNode(0, nullptr);
        size_ = 0;
    }

    // 获取index位置的节点的元素值，找不到返回-1，注意index是从0开始的
    int get(int index)
    {
        if(index >= size_ || index < 0)
        {
            return -1;
        }
        ListNode* cur = dummy_node_;   
        while(index--)
        {
            cur = cur->next;
        }
        // 此时cur就是index上一个位置的那个元素
        return cur->next->val;
    }

    // 在头部添加一个节点
    void addAtHead(int val)
    {
        ListNode* new_node = new ListNode(val, nullptr);
        new_node->next = dummy_node_->next;
        dummy_node_->next = new_node;
        size_++;
    }

    // 在尾部添加一个节点
    void addAtTail(int val)
    {
        ListNode* cur = dummy_node_;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = new ListNode(val, nullptr);
        size_++;
    }

    // 在index位置添加一个node，如果index>size则不添加，如果index<0则在头部添加
    void addAtIndex(int index, int val)
    {
        if(index > size_)
        {
            return;
        }
        if(index < 0)
        {
            addAtHead(val);
        }

        // ListNode* cur = dummy_node_->next;   // 注意这里不能是next
        ListNode* cur = dummy_node_;
        while(index--)
        {
            cur = cur->next;
        }
        // 此时cur就是index上一个位置的那个元素
        ListNode* new_node = new ListNode(val, nullptr);
        new_node->next = cur->next;
        cur->next = new_node;
        size_++;
    }

    // 索引有效则删除
    void deleteAtIndex(int index)
    {   
        if(index >= size_ || index < 0)
        {
            return;
        }

        ListNode* cur = dummy_node_;
        while(index--)
        {
            cur = cur->next;
        }
        // 此时cur就是index上一个位置的那个元素
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size_--;
    }
private:
    int size_;    // 链表中所有节点的个数
    ListNode* dummy_node_;   // 虚拟头节点，方便操作链表
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */