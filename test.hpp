#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

void moveZeroes(vector<int> &nums)
{
    int idx = 0;
    for(int i = 0 ; i < nums.size(); i++)
        if(nums[i] != 0)
            nums[idx++] = nums[i];
    for(; idx < nums.size(); idx++)
        nums[idx] = 0;
}
