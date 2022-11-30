#pragma once
#include <iostream>
#include <vector>

using namespace std;


// 1.真正执行数组合并
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // 初始化合并后的新数组
    int size = nums1.size()+nums2.size();
    vector<int> nums(size, 0); 
    int idx1 = 0, idx2 = 0;

    for(int cur = 0; cur < size; cur++)
    {
        // 都没有超过索引，则判断两个数谁更小
        if(idx1 < nums1.size() && idx2 < nums2.size())
            nums[cur] = nums1[idx1] < nums2[idx2] ? nums1[idx1++] : nums2[idx2++];
        // 否则肯定是有一个超过索引了，则只能选择剩下的没有超过索引的数组中的数
        else if(idx1 < nums1.size())
            nums[cur] = nums1[idx1++];
        else 
            nums[cur] = nums2[idx2++];
    }

    // 合并后是奇数长度
    if(size % 2)
        return nums[size / 2];
    
    // 合并后是偶数长度
    return (nums[size/2 - 1] + nums[size/2]) / 2.0;
}


// 2.只遍历数组（且只需要遍历一半），不进行数组合并
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // 定义两个数记录结果，因为如果有偶数个数则需要求两个数的平均
    int pre = 0;
    int cur = 0;

    // 总长度size，遍历次数就是size/2
    int size = nums1.size() + nums2.size();
    int idx1 = 0, idx2 = 0;   // 两个数组的索引
    for(int i = 0; i <= size/2; i++)
    {
        // 1.更新前一个数
        pre = cur;

        // 2.更新当前的数
        if(idx1 < nums1.size() && idx2 < nums2.size())
            cur = nums1[idx1] < nums2[idx2] ? nums1[idx1++] : nums2[idx2++];
        else if(idx1 < nums1.size())
            cur = nums1[idx1++];
        else 
            cur = nums2[idx2++];
    }

    // 如果是奇数个长度
    if(size % 2)
        return cur;
    
    // 否则是偶数个长度，则返回平均值
    return (pre + cur) / 2.0;
}