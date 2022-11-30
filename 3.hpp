#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> umap;   // <字符，出现的最大位置>
        int result = 0;  // 最长的长度
        int left = 0;    // [left, right]滑动窗口
        for(int right = 0; right < s.size(); right++)
        {
            if(umap.find(s[right]) != umap.end())  // 有这个字符
            {   
                left = umap[s[right]] + 1;  // 更新滑窗左边界
                umap[s[right]] = right;     // 更新umap中字符最右边的位置
            }
            else
            {
                umap.insert({s[right], right});   // 否则插入新的键值对
            }
            result = max(result, right - left + 1);  // 长度
        } 

        return result;
    }


    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> uset;   // 存储滑窗中存在的字符
        int result = 0;  // 最长的长度
        int left = 0;    // [left, right]滑动窗口
        for(int right = 0; right < s.size(); right++)
        {
            // 如果滑窗中有这个字符，则一直移动左边界
            while(uset.find(s[right]) != uset.end()) 
                uset.erase(s[left++]);

            // 运行到这里，滑窗中没有重复的字符
            result = max(result, right - left + 1);  // 长度
            uset.insert(s[right]);   // 插入当前字符
        } 

        return result;
    }
};