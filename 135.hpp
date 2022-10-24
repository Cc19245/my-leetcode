/**
 * @file 135.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 0.每个孩子至少发一个糖果，所以全都初始化成1
        vector<int> candy_vec(ratings.size(), 1);  

        // 1.从前向后遍历，统计右 > 左的情况分发糖果数量
        for(int i = 0; i < ratings.size() - 1; i++)
            if(ratings[i] < ratings[i+1])   // 左 < 右
                candy_vec[i+1] = candy_vec[i] + 1;
        
        // 2.从后往前遍历，统计左 > 右的情况分发糖果数量，并且和之前 右 > 左的情况对比，
        //   结果取最大值，满足比当前值是局部最大的情况
        for(int i = ratings.size() - 1; i > 0; i--)
            if(ratings[i - 1] > ratings[i])   // 左 > 右
                // 左边糖果数量取决于 左<右 和 左>右 的结果中的最大值
                candy_vec[i - 1] = max(candy_vec[i - 1], candy_vec[i] + 1);

        // 3.统计结果
        int result = 0;
        for(auto& can : candy_vec)
            result += can;
        
        return result;
    }
};
