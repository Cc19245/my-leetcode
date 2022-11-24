#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> umap1;   // 使用unordered_map即可
        unordered_map<char, char> umap2;   

        for(int i = 0; i < s.size(); i++)
        {
            // 1.map1、2中都没有对应字符出现过，说明是全新的对应关系，加入即可
            if(umap1.find(s[i]) == umap1.end() && umap2.find(t[i]) == umap2.end())
            {
                umap1[s[i]] = t[i];
                umap2[t[i]] = s[i];
            }
            // 2.map1、2中都有对应的字符出现，看是否匹配
            else if(umap1.find(s[i]) != umap1.end() && umap2.find(t[i]) != umap2.end())
            {
                if(umap1[s[i]] != t[i] || umap2[t[i]] != s[i])
                    return false;
            }
            // 3.map1、2中一个出现过，一个没出现过，肯定不匹配
            else
                return false;
        }

        return true;
    }
};