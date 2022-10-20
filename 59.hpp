#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0)); 
        int loop = n / 2;
        int margin = 0;
        int index = 1;

        while(loop--)
        {
            int i = margin;
            int j = margin;
            int rd_border = n - 1 -margin;   // 右边界，下边界
            int lu_border = margin;   // 左边界，上边界

            for(; j < rd_border; j++)
                result[i][j] = index++;
            
            for(; i < rd_border; i++)
                result[i][j] = index++;

            for(; j > lu_border; j--)
                result[i][j] = index++;
            
            for(; i > lu_border; i--)
                result[i][j] = index++;

            margin++;
        }

        if(n % 2)
            result[n/2][n/2] = n*n;
        
        return result;
    }
};