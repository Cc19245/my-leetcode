#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();   // 防止k过大

        // 左移：先旋转子串，再旋转整个字符串；右移：先旋转子串，再旋转整个字符串
        reverse(nums.begin(), nums.end());          // 先旋转整个数组
        reverse(nums.begin(), nums.begin() + k);    // 在旋转前半部分
        reverse(nums.begin() + k, nums.end());  // 最后旋转后半部分
    }
};