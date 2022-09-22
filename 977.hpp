/**
 * @file 977.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-22
 * 
 * 有序数组的平方，给你一个非降序排列的数组，其中可能有负数。返回数组的平方，要求返回的数组仍然是非降序排列
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力方法，先全部平方一遍(复杂度n)，然后对数组排序（复杂度nlogn）
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for(size_t i = 0; i < nums.size(); i++)
        {
            nums.at(i) *= nums.at(i);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};


// 双指针法，上面的算法没有利用给的数组原来就是有序的这个条件。比如数组是[-3, -2, 1, 2, 4]
// 由于负数的存在，可以知道最终平方后的数组的最大值可能在原数组的最左边或者最右边。也就是说，
// 从最右往左(从大到小)看平方后的数组的话，其元素的来源应该是原数组的左边或者右边的值，所以可以
// 从原数组的最左边和最右边两头往中间看，依次对比他们哪个值更大。这样的时间复杂度就是n
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        size_t k = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for(size_t i = 0, j = nums.size() - 1; i <= j; )
        {
            if(nums[i]*nums[i] < nums[j]*nums[j])
            {
                result[k--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};