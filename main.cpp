#include <iostream>
#include <vector>

#include "704.hpp"
// #include "27.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Solution sol;
    std::vector<int> nums = {1, 2, 4, 5, 7, 9};
    int target = 10;
    int result = sol.search(nums, target);

    std::cout << "result = " << result << std::endl;
    std::cout << "hello world" << std::endl;

    return 0;
}