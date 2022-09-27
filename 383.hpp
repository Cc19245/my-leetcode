/**
 * @file 383.hpp
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
#include <string>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int map[26] = {0};
        for(auto& s : magazine)
            map[s - 'a']++;
        for(auto& s : ransomNote)
            map[s - 'a']--;
        for(auto& m : map)
            if(m < 0)
                return false;
        return true;
    }
};