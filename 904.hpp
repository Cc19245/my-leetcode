/**
 * @file 904.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map <int, int> basket;   // <篮子中的水果种类， 该种水果的个数>
        
        int max = -1;   // 最终返回的结果
        int left = 0;  // 左边的索引
        for(int right = 0; right < fruits.size(); right++)
        {
            basket[fruits[right]]++;   // 该种水果的个数+1

            while(basket.size() > 2)
            {
                basket[fruits[left]]--;   // 左边界的滑出，该种水果数量--
                if(basket[fruits[left]] == 0)  // 如果该种水果的数量=0，说明没有这种水果了
                {
                    basket.erase(fruits[left]);
                }
                left++;   // 左边的索引++
            }

            // 运行到此，窗口中的水果种类一定<=2
            int len = right - left + 1;   // len就是水果的个数，注意不要忘了+1，因为right/left都是索引
            max = len > max ? len : max;
        }
        return max;
    }
};