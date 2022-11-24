#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> result;   // 其实最后里面的字母是char就行，这里用string也无所谓

        int hash[26] = {0};   // 记录最后总的结果，即各个字符串中字母出现次数的最小值，即出现次数的交集
        
        // 1.先统计第一个子串中出现的情况
        for(int i = 0; i < words[0].size(); i++)
            hash[words[0][i]-'a']++;

        // 2.再统计其他子串出现字母的情况，并对hash表取最小的值
        for(int i = 1; i < words.size(); i++)
        {
            int tmp_hash[26] = {0};   // 当前子串的字母出现情况
            for(int j = 0; j < words[i].size(); j++)
                tmp_hash[words[i][j]-'a']++;
            // 遍历hash表，取最小值
            for(int k = 0; k < 26; k++)
                hash[k] = min(hash[k], tmp_hash[k]);  
        }

        // 3.此时hash中存的就是每个字母出现的次数，转成结果就行了
        for(int i = 0; i < 26; i++)
        {
            while(hash[i]--)   // 有多个字符
            {
                string s(1, i+'a');   // i + 'a'就是根据索引，变成字母
                result.push_back(s);
            }
        }

        // 4.最后返回结果
        return result;
    }
};