#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <functional>

int main()
{
    std::vector<int> array;
    int buffer{0};

    std::fstream infile{"in1.txt"};
    while (infile >> buffer)
    {
        array.push_back(buffer);
    }

    int greater{0};

    for (int i = 1; i < array.size(); ++i)
    {
        if (array[i] > array[i - 1])
            ++greater;
    }

    std::cout << "**** PART 1 ****" << std::endl;
    std::cout << greater << std::endl;

    greater = 0;

    // This time start from i=0
    int window_i{0}, window_j{0}, j{0};
    for (int i = 0; i + 3 < array.size(); ++i)
    {
        j = i + 1;
        // std::accumulate uses the addition by default, supply the binary operator explicitly for practice
        // we also need to specify 1 + the iterator to the final element to be summed
        window_j = std::accumulate(array.begin() + j, array.begin() + 1 + j + 2, 0, std::plus<int>());
        window_i = std::accumulate(array.begin() + i, array.begin() + 1 + i + 2, 0, std::plus<int>());
        if (window_j > window_i)
            ++greater;
    }

    // Same logic as in day1.cpp
    /*
    for (int i = 3; i < array.size(); ++i)
    {
        window_j = std::accumulate(array.begin() + i - 2, array.begin() + 1 + i, 0, std::plus<int>());
        window_i = std::accumulate(array.begin() + i - 3, array.begin() + 1 + i - 1, 0, std::plus<int>());

        if (window_j > window_i)
            ++greater;
    }
    */

    std::cout << "**** PART 2 ****" << std::endl;
    std::cout << greater << std::endl;

    return 0;
}
