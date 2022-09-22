/**
 * @file 209.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-22
 * 
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，
并返回其长度。如果不存在符合条件的子数组，返回 0。

示例：

输入：s = 7, nums = [2,3,1,2,4,3] 输出：2 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 暴力解法：从头开始往后面找子数组，一旦找到长度最小的，那么就切换最开始的元素的位置。遍历完所有的最开始元素位置
// 也就找到了所有的最小长度的子数组。由于遍历最开始元素位置一个for循环是n，内部找子数组的时候还要一个for循环，
// 因此时间复杂度是n^2
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0;
        int len = 0;
        // i表示从数组哪个元素开始往后找
        for(int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            // 从i当前的位置开始往后累加数组，直到找到满足条件的子数组。如果找到头也不满足条件，那么就下一次循环
            for(int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if(sum >= target)
                {
                    len = j - i + 1;
                    result = result > len ? len : result;
                    // 注意我们是找最短的子序列，因此不管上面的result是不是取了最新的len，这里都要break掉
                    // 因为以当前i开头的子数组的最短长度已经找到了
                    break;   
                }
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};


// 上面暴力求解算法导致时间复杂度高的原因在哪里？就是因为有两个for循环，但是很明显其中一个for循环
//   是必须的，因为不论什么解法肯定要一个for循环把数组进行遍历。问题就出在第二个for循环上，它从i的位置开始循环
//   向后求和寻找满足条件的子数组。但是其实可以看到，i=0的时候往后循环求和，和i=1的时候往后循环求和，他们求和
//   的数组之间是有很大部分的重叠的。比如nums = [2, 1, 4, 2, 5, 3], target = 7。则i=0时求和的数组是
//   [2, 1, 4]，i=1时求和的数组是[1, 4, 2]，这两个数组中间高度重合了[1, 4]这两个元素，这就导致暴力求解过程中
//   有很多重复的计算量。
// 滑动窗口算法（双指针算法）：分析完上面暴力求解算法的问题之后，可以发现如果能够重复利用中间的元素，那么就会降低
//   求解的计算量。所以就利用双指针，让尾指针遍历这个数组，头指针根据是否满足子数组的和>target进行移动，这样
//   首尾指针都向后移动，就可以高效的重复利用中间重合的数组
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0; // 滑窗中子数组的总和
        int len = 0; // 滑窗子数组的长度
        int i = 0;   // 首指针的位置
        // j表示尾指针，遍历整个数组
        for(int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while(sum >= target)
            {
                len = j - i + 1;
                result = result > len ? len : result;
                // 精髓所在：把首指针向后移动一个位置，同时将整个滑窗中子数组的和减掉首指针的这个元素值
                // 从而达到高效利用滑窗中重复元素的作用
                sum -= nums[i++]; 
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};