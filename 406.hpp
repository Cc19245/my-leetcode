/**
 * @file 406.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-25
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
private:
    // 这里必须是static，为什么？
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0])  // 如果身高相同，则按照序号小的在前进行排列
            return a[1] < b[1];
        return a[0] > b[0];  // 身高不同则按照身高排列，身高高的在前
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // 1.先对people按照身高从高到低进行排列，如果身高相同，则按照后面的序号小的在前进行排序
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> result;  // 最终结果

        for(int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];   // 在最终结果中的位置
            result.insert(result.begin()+pos, people[i]);  // 在对应位置插入
        }

        return result;
    }
};


