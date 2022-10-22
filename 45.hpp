#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int jump(vector<int> &nums)
    {
        // 判断特殊情况：如果只有一个数，那么直接就是在终点了，不用跳
        if (nums.size() == 1)
            return 0;

        int ans = 0;   // 最终跳的步数
        int this_cover = nums[0];   // 开始位置覆盖的范围
        int next_cover = 0;   // 如果跳到当前覆盖范围内的所有位置，可以覆盖到的最大的新的范围

        // 先判断从初始位置一步能不能跳到最终位置，如果能则直接返回结果
        if(this_cover >= nums.size() - 1)   
            return 1;
        
        // 运行到这里，说明要多跳几步
        int i = 0;
        for(; i <= this_cover; i++)
        {
            // 遍历当前范围内的所有位置，寻找下一步的最大范围
            next_cover = max(next_cover, i + nums[i]);  // 求下一步的最大范围
            
            // 遍历到当前范围内的最后一个位置，那么上面也把下一步的最大范围next_cover统计出来了
            //  因此更新遍历的this_cover，继续遍历
            if(i == this_cover)  
            {
                ans++;  // 要新跳一步了
                this_cover = next_cover;   // 下次遍历的最大范围更新
                // 如果下次遍历的最大范围覆盖到数组末尾了，那么不用再遍历了，已经找到最小步数了
                if(this_cover >= nums.size() - 1)
                {
                    ans++;  // 在下一个范围中跳一步，就直接到终点了
                    return ans;   // 返回最终结果
                }
            }
        }

        // 实际不会运行到这里，这只是为了满足函数有返回值的要求
        return 0;
    }
};
