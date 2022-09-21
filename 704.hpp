/**
 * @file 704.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-21
 * 
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
 * 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 * 
 * 注意二分查找的使用条件：
 *  1.数组有序排列
 *  2.数组中没有重复的数字，这样才能找到唯一解，否则找不到唯一的解
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <vector>

using namespace std;   // 不好的习惯

// [left, right]
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        size_t left = 0;
        size_t right = nums.size() - 1;  // 注意右区间是闭合的，也就是会取到右索引，因此这里是size-1
        while(left <= right)  // left <= right也是有意义的
        {
            size_t middle = left + (right - left) / 2;  // 和(left+right)/2一样的，这样防止溢出
            if(nums.at(middle) > target)  // 左区间
            {
                // middle已经>target了，因此middle一定不会是target，所以调整区间的时候就不用再把middle包括在里面了
                right = middle - 1; 
            }
            else if(nums.at(middle) < target)
            {
                // middle已经<target了，因此middle一定不会是target，所以调整区间的时候就不用再把middle包括在里面了
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};

// [left, right)
class Solution2
{
public:
    int search(vector<int>& nums, int target) 
    {
        size_t left = 0;
        size_t right = nums.size(); // 注意右索引是取不到的，因此这里为了包括整个数组，要使用size，而非size-1
        while(left < right)
        {
            size_t middle = left + (right - left)/2;
            // middle > target，那么middle一定不会是target，但是由于右索引是取不到的，所以这里调整
            // 右索引要包括middle，而不是middle-1(这样就把middle-1这个可能的解漏掉了)
            if(nums.at(middle) > target)
            {
                right = middle;
            }
            // 左索引是能取到的，所以如果左索引就不用包括middle了
            else if(nums.at(middle) < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};


// 下面的网上没有写，使用这种方法主要是看自己到底有没有理解
//! 有问题！不尝试了
//? 最新解答：没问题了，主要是索引，此时要取右边的索引，因此middle的结果要+1
// (left, right]
class Solution3
{
public:
    int search(vector<int>& nums, int target) 
    {
        // 注意左开右闭的的区别
        int left = -1;   
        int right = nums.size() - 1;   
        while(left < right)
        {
            //; 这里就出问题了，如果数组中只有一个数，那么left=-1, 右边是（0- -1）/2 =0, 结果middle是-1
            int middle = left + (right - left)/2 + 1;  //; 注意：这里改成+1就没问题了
            // size_t middle = (left + right) / 2;
            if(nums.at(middle) > target)
            {
                right = middle - 1;
            }
            else if(nums.at(middle) < target)
            {
                left = middle;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};


//! 问题：下面这个执行超时，还是有点问题，感觉主要还是索引的问题
// (left, right)
class Solution4
{
public:
    int search(vector<int>& nums, int target) 
    {
        // 注意左开右开的的区别
        int left = -1;   
        int right = nums.size();   
        while(left < right)
        {
            int middle = left + (right - left + 1)/2;  //; 注意：这里改成+1就没问题了
            // size_t middle = (left + right) / 2;
            if(nums.at(middle) > target)
            {
                right = middle;
            }
            else if(nums.at(middle) < target)
            {
                left = middle;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};