#include <iostream>
#include <vector>

#include "54.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Solution sol;
    
    vector<vector<int>> a = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    vector<vector<int>> b = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    vector<vector<int>> c = {{1, 2, 3, 4}, {1, 2, 3, 4}};
    vector<vector<int>> d = {{2, 5}, {8, 4}, {0, -1}};   // [[2,5],[8,4],[0,-1]]
    vector<vector<int>> e = {{2, 8, 0}, {5, 4, -1}}; 

    vector<int> res = sol.spiralOrder(a);
    for(auto bb:res)
        std::cout << bb << " ";
    std::cout << std::endl;

    res = sol.spiralOrder(b);
    for(auto bb:res)
        std::cout << bb << " ";
    std::cout << std::endl;

    res = sol.spiralOrder(c);
    for(auto bb:res)
        std::cout << bb << " ";
    std::cout << std::endl;

    res = sol.spiralOrder(d);
    for(auto bb:res)
        std::cout << bb << " ";
    std::cout << std::endl;

    res = sol.spiralOrder(e);
    for(auto bb:res)
        std::cout << bb << " ";
    std::cout << std::endl;

    return 0;
}