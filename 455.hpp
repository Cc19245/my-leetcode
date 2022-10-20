#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // 注意必须要先排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int index = 0;
        for(int i = 0; i < s.size(); i++)
        {
            // 首先index < g.size()保证还有没喂的孩子，防止饼干个数过多，超过孩子总数
            // 遍历所有饼干，只要当前饼干可以喂饱当前孩子，就使用这个饼干；然后继续遍历下一个饼干，喂下一个孩子
            if(index < g.size() && g[index] <= s[i])
                index++;
        }

        return index;
    }
};