#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;

        for (; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                int len = right - left + 1;
                result = result > len ? len : result;
                sum -= nums[left++];
            }
        }

        result = (result == INT32_MAX) ? 0 : result;
        return result;
    }

    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;

        while (right < nums.size())
        {
            if (sum < target)
            {
                sum += nums[right];
                right++;
                if(sum >= target)
                {
                    int len = right - left + 1;
                    result = result > len ? len : result;
                }
            }
            else
            {
                sum -= nums[left];
                left++;
                if(sum >= target)
                {
                    int len = right - left + 1;
                    result = result > len ? len : result;
                }
            }
        }
        while(sum >= target)
        {
            sum -= nums[left];
            left++;
            if(sum >= target)
            {
                int len = right - left + 1;
                result = result > len ? len : result;
            }
        }

        result = (result == INT32_MAX) ? 0 : result;
        return result;
    }
};