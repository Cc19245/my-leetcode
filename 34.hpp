/**
 * @file 34.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * 给定一个非降序的数组nums和一个目标数据target，返回这个数在nums中的左右边界。如果这个数在nums中不存在，返回[-1,-1]
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // 情况一
        if (leftBorder == -2 || rightBorder == -2)
            return {-1, -1};
        // 情况三
        if (rightBorder - leftBorder > 1)
            return {leftBorder + 1, rightBorder - 1};
        // 情况二
        return {-1, -1};
    }

private:
    // 二分查找，寻找target的右边界（不包括target）
    // 如果rightBorder为没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
    int getRightBorder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        int rightBorder = -2;        // 记录一下rightBorder没有被赋值的情况
        while (left <= right)        // 当left==right，区间[left, right]依然有效
        {
            int middle = left + ((right - left) / 2); // 防止溢出 等同于(left + right)/2
            if (nums[middle] > target)
            {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            }
            else
            { // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }

    // 二分查找，寻找target的左边界leftBorder（不包括target）
    // 如果leftBorder没有被赋值（即target在数组范围的右边，例如数组[3,3],target为4），为了处理情况一
    int getLeftBorder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        int leftBorder = -2;         // 记录一下leftBorder没有被赋值的情况
        while (left <= right)
        {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target)
            { // 寻找左边界，就要在nums[middle] == target的时候更新right
                right = middle - 1;
                leftBorder = right;
            }
            else
            {
                left = middle + 1;
            }
        }
        return leftBorder;
    }
};


// 自己写的情况 
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = getLeftBorder(nums, target);
        int right = getRightBorder(nums, target);
        if(left == -2 || right == -2)
            return {-1, -1};

        if(right - left > 1)
            return {left+1, right-1};

        return {-1, -1};
    }

private:
    // 寻找target在nums中的左边界
    int getLeftBorder(vector<int> &nums, int target)
    {
        // [left,right]二分
        int left = 0;
        int right = nums.size() - 1;
        // 注意为什么初始化成-2，因为一直在缩小的right就是我们求的左边界，如果根本不存在左边界，
        // 比如找在[1, 2, 3]中找5，那么left一直在变大，而right却是没有变化的。
        // 那么为什么要初始化成-2呢？初始化成-1行不行？答案是不行的，因为这个-2是在指示right到底有没有移动过，
        // 如果是在[1, 2, 3]中找-5，那么right一直减小，直到最后right
        int left_border = -2;    
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(nums.at(middle) >= target)
            {
                right = middle - 1;
                left_border = right;
            }
            else
            {
                left = middle + 1;
            }
        }

        return left_border;
    }

     // 寻找target在nums中的右边界
    int getRightBorder(vector<int> &nums, int target)
    {
        // [left,right]二分
        int left = 0;
        int right = nums.size() - 1;
        int right_border = -2;    
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(nums.at(middle) > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
                right_border = left;
            }
        }

        return right_border;
    }
};

// [1, 2, 3]中寻找5的左右边界：
//   左边界：要不断左移right，直到不满足while循环。这种情况下显然right一直没动，left不断右移，因此最后left_border = -2
//   右边界：要不断右移动left，直到不满足while循环。这种情况下left不断右移，直到最后一个，所以right_border = 3(注意是3，不是2)
// [1, 2, 3]中寻找-5的左右边界是类似的，左边界是-1，右边界是-2

// [1, 2, 4]中寻找3：
//   左边界：左移right，从4移动到2结束，所以最后left_border = 1
//   右边界：右移left，从1移动到4结束，所以最后right_border = 2
// 可见由于2和4中间不存在3，所以最后right_border - left_border = 1

// [1, 2, 3, 4]中寻找3：
//   左边界：左移right，从4移动到2结束，所以最后left_border = 1
//   右边界：右移left，从1移动到4结束，所以最后right_border = 3
// 所以最后right_border - left_border = 2 > 1

// [1, 2, 3, 3, 3, 4]中寻找3：
//   左边界：左移right，从4移动到2结束，所以最后left_border = 1
//   右边界：右移left，从1移动到4结束，所以最后right_border = 5
// 所以最后right_border - left_border = 4 > 1