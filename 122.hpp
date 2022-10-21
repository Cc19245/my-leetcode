#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int pre = 0;
        int cur = 1;
        int sum = 0;
        while(cur < prices.size())
        {
            int diff = prices[cur++] - prices[pre++];
            if(diff > 0)
                sum += diff;
        }

        return sum;
    }
};