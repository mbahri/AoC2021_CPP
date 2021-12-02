#include <iostream>
#include <fstream>
#include <vector>

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

    for (int i = 3; i < array.size(); i += 1)
    {
        if (array[i] + array[i - 1] + array[i - 2] > array[i - 1] + array[i - 2] + array[i - 3])
            ++greater;
    }

    std::cout << "**** PART 2 ****" << std::endl;
    std::cout << greater << std::endl;

    return 0;
}
