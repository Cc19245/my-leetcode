/**
 * @file 151.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        removeSpaces(s);   // 先删除多余空格
        reverseString(s, 0, s.size()-1);   // 将整个字符串翻转
        
        // 再把每个单词翻转
        int start = 0;
        // 注意这里的细节，是<=s.size()，原因在于里面判断的时候是到end == s.size(),
        // 因为reverseString传的是end-1，就相当于把最后一个单词后面又给他加一个虚拟的空格
        for(int end = 0; end <= s.size(); end++)
        {   
            // 寻找到一个单词，或者说是最后一个单词
            if(s[end] == ' ' || end == s.size())
            {
                reverseString(s, start, end-1);  // 翻转这个字符串
                start = end + 1;   // 下一个字符串开始的位置
            }
        }

        return s;
    }

private:
    // 传入字符串和索引，将索引之间的字符串进行反序，注意是[start, end]闭区间
    void reverseString(string& s, int start, int end)
    {
        while(start < end)
        {
            char tmp = s[start];
            s[start++] = s[end];
            s[end--] = tmp;
        }
    }

    // 双指针法删除多余的空格，注意这个还是按照单词的思想来处理，就是每个单词之间添加一个空格
    void removeSpaces(string& s)
    {
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++)
        {
            // 这个字符不是空格，说明遇到了一个单词的开始字母，把这个单词填充到最终的字符串中
            if(s[fast] != ' ')
            {
                // 不是第一个单词的话，添加这个单词之前要和上个单词之间填充空格
                if(slow != 0)
                    s[slow++] = ' ';   
                
                // 填充这个单词
                while(fast < s.size() && s[fast] != ' ')
                    s[slow++] = s[fast++];
            }
        }

        // 处理完毕，对s进行瘦身
        s.resize(slow);
    }
};