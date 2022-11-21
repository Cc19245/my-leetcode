#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        // 小于三个元素肯定不是山峰，直接返回false
        if(arr.size() < 3)
            return false;
        
        // 左右指针
        int left = 0;
        int right = arr.size() - 1;

        // 左指针按照升序一直右移，右指阵按照降序一致左移
        while(left < arr.size()-1 && arr[left] < arr[left+1])
            left++;
        while(right > 0 && arr[right-1] > arr[right])
            right--;
        
        // 最后判断结果：左右指针相遇，并且都不是在起点（也就是都进行了移动）
        if(left == right && left != 0 && right != arr.size()-1)
            return true;
        
        return false;
    }
};