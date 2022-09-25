/**
 * @file 76.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t) 
    {
        unordered_map <char, int> t_map;   // <字符，字符个数>
        unordered_map <char, int> s_map;   // <字符，字符个数>

        // 先统计t中字符的情况
        for(auto& t_char:t)
        {
            t_map[t_char]++;
        }

        int left = 0;  // 左边的索引
        int cnt = 0;  
        string res;    // 最终返回的字符串
        for(int right = 0; right < s.size(); right++)
        {
            s_map[s[right]]++;    // 这个字符的个数++
            
            // 注意这里的判断和水果成篮的判断又不一样了，因为这里在s字符串中寻找指定的字符可以是不连续的
            if(s_map[s[right]] <= t_map[s[right]])
                cnt++;   // 满足条件的字符类型个数++
            
            // 由于窗口右移的一下，可能导致某种类型的字符个数超过需要的个数，因此需要缩减窗口
            // 1.比如[A, B, C, D, A]，此时如果滑动到了最后一个A，那么A的总个数就变成了3，可能大于需要的个数
            // 2.另一中情况是根本不需要这个字符。比如1中把A滑出去之后，变成[B, C, D, A]，假设我不需要B，
            //   那么此时会继续把B滑出去
            while(s_map[s[left]] > t_map[s[left]])
                s_map[s[left++]]--;   // 一直右移left，并且滑窗中这个字符的个数-1

            if(cnt == t.size())
            {
                if(res.empty() || right - left + 1 < res.size())
                    res = s.substr(left, right - left + 1);
            }
        }
        return res;
    }
};