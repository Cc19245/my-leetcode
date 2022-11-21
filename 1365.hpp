#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        // 1.对数组元素进行排序，则排序后的索引就是比他小的数组的元素个数
        vector<int> vec = nums;   // 注意要复制数组，否则会打乱数组的原有顺序
        sort(vec.begin(), vec.end());

        // 2.定义哈希数组并填充
        int hash[101] = {0};   // 题目说了 0 <= nums[i] <= 100，也就是hash表的值都在这些数中间
        // 填充哈希数组：从后往前填充，这样保证相同数字其索引都是左边数字的索引，才等于把它小的元素个数
        for(int i = vec.size()-1; i >=0; i--)
            hash[vec[i]] = i;   // 键是数值，值是索引
        
        // 3.遍历原数组，根据元素的值到哈希表中寻找对应的索引，就是数组中值比他小的元素个数
        for(int i = 0; i < nums.size(); i++)
        {
            vec[i] = hash[nums[i]];   // 这里复用vec数组来存储最终结果，节省空间
        }

        return vec;
    }
};