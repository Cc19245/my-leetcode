/**
 * @file 27.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-21
 * 
 * 原地移除数组中的元素，不能额外开辟空间。这个跟vins-mono中的数组瘦身是一模一样的！
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <vector>

using namespace std; // 不好的习惯


// 暴力求解，两个for循环，第1层遍历数组中所有元素，遇到要移除的元素之后就开启第2个for循环，把后面的元素都前移
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        size_t size = nums.size();
        // 首先注意这里为什么为什么使用的是size这个变量，而不是nums.size()，因为我们要访问的
        // 数组的长度是变化的，但是我们没有调整数组的size，所以不能使用nums.size
        for(size_t i = 0; i < size; i++)
        {
            if(nums.at(i) == val)
            {
                for(size_t j = i + 1; j < size; j++)
                {
                    nums.at(j-1) = nums.at(j);
                }
                // 注意理解这里为什么要把i--，因为这个位置的数据如果是val，把后面的移动之后，
                // i位置的数变成了移动之前i+1位置的数。但是执行外这次的i的for循环之后会把i++,
                // 此时所以就跳到了i+1（即原来的i+2位置的数），如果这里不执行i--的话，相当于原来i+1
                // 位置的数就没有进行判断
                i--;
                size--;
            }
        }
        return size;
    }
};


// 双指针方法，和vins-mono中的数组瘦身是一样的
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution2
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        size_t slow_index = 0;
        // 双指针法（也叫做快慢指针法），实际上就是fast指针遍历原来的数组，去找我们要的下一个元素的位置
        // 然后slow则标志我们最后得到的新的数组的索引。这样每次找到要的元素之后只需要复制要的这个元素
        // 而不需要把后面所有的元素都移动一遍
        for(size_t fast_index = 0; fast_index < nums.size(); fast_index++)
        {
            if(nums.at(fast_index) != val)
            {
                nums.at(slow_index) = nums.at(fast_index);
                slow_index++;
            }
        }
        return slow_index;
    }
};