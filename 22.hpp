#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> result;   // 最终收集的结果
    string path;   // 当前收集的路径

    void backtracking(int left, int right, int n)
    {
        // 2.回溯终止条件：左右括号都收集满了
        if(left == n && right == n)
        {
            result.push_back(path);
            return;
        }

        // 3.开始递归和回溯
        // 3.1.还有剩余的(，那么(是可以无条件放的，都合法，只需要等待后面用)匹配它即可
        if(left < n)   
        {
            path.push_back('(');  // 加入一个(
            backtracking(left+1, right, n);   // 递归，选择后面的括号
            path.pop_back();   // 回溯，把上面加入的(弹出
        }
        // 3.2.还有剩余的), 并且当前已有的(个数 > 已有的)个数，那么可以加入)
        if(right < n && left > right)
        {
            path.push_back(')');   // 加入一个)
            backtracking(left, right+1, n);
            path.pop_back();   // 回溯，把上面加入的)弹出
        }
    }

    vector<string> generateParenthesis(int n)
    {
        backtracking(0, 0, n);
        return result;
    }
};