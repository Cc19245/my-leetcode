#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "15.hpp"

using namespace std;


int main(int argc, char** argv)
{
    Solution sol;
    vector<int> a = {-4, -1, -1, 0, 1, 2};

    auto res = sol.threeSum(a);
    // cout << res.size() << endl;
    for(auto& nums : res)
    {
        cout << endl;
        for(auto& num : nums)
            cout << num << ' ';
    }
        
        
    return 0;
}