/**
 * @file 18.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * 四数之和
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int last_a = INT32_MAX;
        // 遍历a
        for(int i = 0; i < nums.size(); i++)
        {
            int last_b = INT32_MAX;
            int a = nums[i];
            // 首先这里剪枝处理存在问题，因为此时的target不是0，如果它是负数，这么判断就有问题
            // 比如nums = [-4, -3, -2, -1], target=10, a=-4 > -10，但是往后加是存在答案的，不能跳过
            // if(a > target)
            //     return result;

            // 但是仍然可以进行一些剪枝处理，比如如果a>0，说明已经到了正数这边，那么不管target是正是负，都可跳过了
            if(a > target && a > 0)
                // return result;
                break;
            if(a == last_a)
                continue;
            last_a = a;   // 运行到这里说明a没有重复，更新last_a
            
            // 遍历b
            for(int j = i+1; j < nums.size(); j++)
            {
                int b = nums[j];
                // 提前结束，这里同理也要判断(a+b)>0
                if((a+b) > target && (a+b)>0)
                    // 注意这里不能return, 因为可能a很小，b很大了，但是只能说明这次b太大了后面的不用遍历了
                    // 但是下次遍历的a还是很小，然后b也从很小开始遍历，仍然是有解的，所以这里不能直接return
                    // return result;
                    break;
                if(b == last_b)
                    continue;
                last_b = b;    // 运行到这里说明b没有重复，更新last_b
                
                int left = j + 1; 
                int right = nums.size() - 1;
                int last_c = INT32_MAX;
                while(left < right)
                {
                    // 注意这里四个数相加，防止溢出，要先把a单独强制转成long，然后后面的和它加的时候
                    // 就会自动的进行隐式类型转换，变成long
                    if(((long)a + b + nums[left] + nums[right]) == target)
                    {
                        if(nums[left] != last_c)
                        {
                            result.push_back(vector<int>{a, b, nums[left], nums[right]});
                            last_c = nums[left];
                        }
                        // 只要找到了正确答案，不管有没有重复，都要收缩双指针
                        left++;   
                        right--;
                    }
                    else if(((long)a + b + nums[left] + nums[right]) > target)
                        right--;
                    else
                        left++;
                }
            }
        }

        return result;
    }
};