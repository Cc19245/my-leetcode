/**
 * @file 332.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-19
 * 
 * 给定航班列表，重新规划路线
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
private:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    // 注意为什么要用这种方式：因为我们要记录从当前机场出发，可以往哪些机场飞。比如出发机场是A，到达机场
    // 可以是BCD等。还有一个问题是每张机票只能用一次，所以我们还要记录从出发机场飞往达到机场的剩余机票的张数，
    // 比如可能有三张从A飞往B的机票，那么每次遍历机场A的时候，如果向往机场B非，就要先判断是否还有A->B的机票
    // 如果有就可以飞
    unordered_map<string, map<string, int>> targets;

    // ticketNum是一共有多少张机票，result是最终的飞行路线结果
    bool backtracking(int ticketNum, vector<string> &result)
    {
        // 递归终止条件：如果飞行路线中机场个数 = 机票张数 + 1，则说明把所有机票都用完了，
        //             即收集到了一个可能路线
        if (result.size() == ticketNum + 1)
        {
            return true;
        }

        // 开始递归：从路线中最后一个机场出发（也就是上一次到达的机场，或者最初起飞的机场），遍历所有
        //         它可能飞往的达到机场，寻找一条路径
        for (pair<const string, int> &target : targets[result[result.size() - 1]])
        {
            // 如果从当前机场，飞往到达机场的机票还有剩余，那么就还能飞
            if (target.second > 0)
            {
                result.push_back(target.first); // 飞往到达机场，加到路线中
                target.second--;                // 当前机场->到达机场，所以机票张数-1
                // 重要：递归调用，从下一个机场作为起飞点，再次寻找飞往的目的地
                //     (1)如果调用下一个机场的结果是true，说明找到了一条路线，则直接返回
                //     (2)如果调用下一个机场的结果是false，说明没有找到一条完整路线（即走到了死胡同里）
                //        那么就到了下面回溯的过程：即把当前for循环选择的到达机场弹出，换另一个到达机场
                if (backtracking(ticketNum, result))
                    return true;   // 找到一条路线就返回
                result.pop_back(); // 回溯
                // 注意：这里一定不要忘了机票数量++，因为上面--是因为当前位置的到达机场为当前for循环选择的值
                //      （假设是B）的时候，后面调用递归安排后面的路线。一旦后面递归完成，说明当前位置选择
                //      这个for循环的值B经过测试不能满足要求了，所以要把当前选择的到达机场B弹出，然后把
                //      它的机票张数也复原，然后重新选择另一个达到机场C，此时B的机票张数应该还是原来的张数
                //      所以这里回溯的时候一定要把机票张数也++，对机票张数进行复原
                target.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        targets.clear();
        vector<string> result;

        for (const vector<string> &vec : tickets)
        {
            // vec[0]是触发机场的名称，targets[vec[0]]就是取出键对应的值，即<到达机场，剩余机票次数>
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK"); // 起始机场
        backtracking(tickets.size(), result);
        return result;
    }
};

class Solution
{
public:
    unordered_map<string, map<string, int>> targets;  // 记录机票的出发点和达到点
    vector<string> result;   // 最终结果
    bool backtracking(int ticket_num)
    {
        if(result.size() == ticket_num + 1)  // 找到一条合理路径了
            return true;
        
        // 递归：以上一次的达到机场为本次的出发机场，遍历选择本次的到达机场
        for(auto & target : targets[result.back()])
        {
            if(target.second > 0)  // 如果这个到达机场还有机票
            {
                result.push_back(target.first);
                target.second--;
                if(backtracking(ticket_num))  // 选择下一个机场
                    return true;
                target.second++;    // 回溯
                result.pop_back();   
            }
        }

        // 执行到这里的时候，说明没有找到一条完整的路线，所以return false
        return false; 
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        targets.clear(); 
        result.clear();

        // 先统计机票数
        for(auto & ticket : tickets)
        {
            targets[ticket[0]][ticket[1]]++;
        }
        result.push_back("JFK");   // 选择出发机场
        backtracking(tickets.size());   // 遍历选择所有路线
        return result;
    }
};