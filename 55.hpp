#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;

        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            // 跟新新的最大范围
            cover = cover < (i + nums[i]) ? (i + nums[i]) : cover;
            if (cover >= nums.size() - 1) // 一旦可以达到最大范围，直接return
                return true;
        }

        return false;
    }

    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1) // 只有一个数，不用跳就在终点，所以是true
            return true;

        int this_cover = nums[0]; // 当前遍历的最大范围
        int next_cover = 0;       // 从当前遍历的范围中计算下一次遍历的最大范围

        if (this_cover >= nums.size() - 1) // 第一步就能跳到最终位置
            return true;

        // 运行到这里说明第一步调不到终点，还要多跳几步
        int i = 0;
        for (; i <= this_cover; i++) // 遍历当前的范围，寻找下一次的最大范围
        {
            next_cover = max(next_cover, i + nums[i]);
            if (i == this_cover) // 遍历到当前最后一个位置了
            {
                this_cover = next_cover;           // 更新下一次遍历的最大范围
                if (this_cover >= nums.size() - 1) // 一旦可以达到最大范围，直接return
                    return true;
            }
        }

        // 运行到这里，说明无法跳到终点
        return false;
    }
};

bool haveConflict(vector<string> &event1, vector<string> &event2)
{
    int e1_start_h = 10 * (event1[0][0] - '0') + (event1[0][1] - '0');
    int e1_start_m = 10 * (event1[0][3] - '0') + (event1[0][4] - '0');
    int e1_end_h = 10 * (event1[1][0] - '0') + (event1[1][1] - '0');
    int e1_end_m = 10 * (event1[1][3] - '0') + (event1[1][4] - '0');

    int e2_start_h = 10 * (event2[0][0] - '0') + (event2[0][1] - '0');
    int e2_start_m = 10 * (event2[0][3] - '0') + (event2[0][4] - '0');
    int e2_end_h = 10 * (event2[1][0] - '0') + (event2[1][1] - '0');
    int e2_end_m = 10 * (event2[1][3] - '0') + (event2[1][4] - '0');

    int e1_start = e1_start_h * 60 + e1_start_m;
    int e1_end = e1_end_h * 60 + e1_end_m;
    int e2_start = e2_start_h * 60 + e2_start_m;
    int e2_end = e2_end_h * 60 + e2_end_m;

    if (e1_end < e2_start || e2_end < e1_start)
        return false;

    return true;
}

int subarrayGCD(vector<int> &nums, int k)
{
    int result = 0;

    int start = 0;
    int end = 0;

    for (int index = 0; index < nums.size(); index++) 
    {
        if(nums[index] % k)  // 不能被k整除
        {
            end = index - 1;  // [start, end]
            for(int i = start; i <= end; i++)   // 起始位置
            {
                for(int j = i; j <= end; j++)   // 终止位置
                {
                    for(int kk = i; kk <= j; kk++)
                        if(nums[kk] == k)
                        {
                            result++;
                            break;
                        }
                }
            }
            start = index + 1;
        }
    }

    return result;
}
