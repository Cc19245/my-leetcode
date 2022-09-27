/**
 * @file 15.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++)
        {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0)
            {
                return result;
            }
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};



// 自己写
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int last_a = INT32_MAX;
        vector<vector<int>> result;

        for(int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            // 先判断一下，因为可能遍历到某个i的位置，此时a>0，肯定不能组成三元组了，就可以提前结束了
            if(a > 0)
                return result;

            // 保证a的唯一性
            if(a == last_a)
                continue;

            // 执行到这里说明a是唯一的，更新上一次a的值
            last_a = a;   
            int left = i + 1;
            int right = nums.size() - 1;
            int last_b = INT32_MAX;    // 记录上次的b的值，保证唯一性
            while(left < right)
            {
                if((a + nums[left] + nums[right]) == 0) 
                {
                    // b的值没重复，则这次结果可以保存
                    if(nums[left] != last_b)
                    {
                        result.push_back(vector<int>{a, nums[left], nums[right]});
                        last_b = nums[left];   // 更新上次的b值
                    }
                    // 找到a+b+c=0，不管是否有重复，都要把双指针进行收缩
                    left++;
                    right--;
                }
                else if ((a + nums[left] + nums[right]) > 0)
                    right--;
                else
                    left++;
            }   
        }

        return result;
    }
};