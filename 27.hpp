#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int fast = 0;
        int slow = 0;

        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
                nums[slow++] = nums[fast];
        }
        nums.resize(slow);
        return slow;
    }

    int removeElement(vector<int> &nums, int val)
    {
        int new_index = 0;
        for (auto &num : nums)
            if (num != val)
                nums[new_index++] = num;

        nums.resize(new_index);
        return new_index;
    }
};
