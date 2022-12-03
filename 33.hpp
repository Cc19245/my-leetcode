#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if(nums.empty())
            return -1;
        if(nums.size() == 1)
            return (nums[0] == target ? 0 : -1);

        // [left, right] 二分数组，以mid划分数组为[left, mid-1], middle, [mid+1, right]
        // 三种情况：左升序、右无序；左升序、右升序；左无序、右升序
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + (right - left)/2;
            if(nums[middle] == target)
                return middle;
            else
            {
                // 左升序，则应该用左区间去判断边界
                // 注意一定要<=，比如[3,1]中寻找1这种情况。主要就是数组长度为2时，由于/2是向下取整，
                // 所以结果是left = middle。
                if(nums[left] <= nums[middle])   
                {
                    // 结果不在左区间中
                    if(target < nums[left] || target > nums[middle])   
                        left = middle + 1;
                    else    // 结果在左区间中
                        right = middle - 1;     
                }
                else   // 右升序
                {
                    // 结果不在右区间中
                    if(target < nums[middle] || target > nums[right])  
                        right = middle - 1;
                    else
                        left = middle + 1;
                }
            }
        }

        return -1;  // 实际执行不到这里
    }
};