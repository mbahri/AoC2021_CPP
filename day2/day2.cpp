#include <iostream>
#include <fstream>
#include <vector>

enum Command
{
    UP,
    DOWN,
    FORWARD
};

typedef std::vector<std::pair<Command, int>> OrderedPairs;

Command parseCommand(const std::string &cmd);
void doPart1(const OrderedPairs &commands);
void doPart2(const OrderedPairs &commands);

int main(int argc, char **argv)
{
    // Buffers to read the input
    std::string commandString;
    int amount{0};

    // "Map" to read the file once
    OrderedPairs commands;

    std::fstream infile("in2.txt");
    while (infile >> commandString >> amount) {
        // Write the construction of the pair explicitly for practice
        // but push_back (insert with a Map) would probably accept a list {}
        commands.push_back(std::pair<Command, int>{parseCommand(commandString), amount});
    }

    doPart1(commands);
    doPart2(commands);

    return EXIT_SUCCESS;
}

void doPart1(const OrderedPairs &commands)
{
    long long hpos{0}, depth{0};
    for (const auto &pair : commands)
    {
        switch (pair.first)
        {
        case FORWARD:
            hpos += pair.second;
            break;
        case UP:
            depth -= pair.second;
            break;
        case DOWN:
            depth += pair.second;
            break;
        default:
            throw std::invalid_argument("Invalid input!");
        }
    }

    std::cout << "***** PART 1 ****" << std::endl;
    std::cout << "Hpos: " << hpos << " Depth: " << depth << std::endl;
    std::cout << "Product: " << hpos * depth << std::endl;
}

void doPart2(const OrderedPairs &commands)
{
    long long hpos{0}, depth{0}, aim{0};
    for (const auto &pair : commands)
    {
        switch (pair.first)
        {
        case FORWARD:
            hpos += pair.second;
            depth += aim * pair.second;
            break;
        case UP:
            aim -= pair.second;
            break;
        case DOWN:
            aim += pair.second;
            break;
        default:
            throw std::invalid_argument("Invalid input!");
        }
    }

    std::cout << "***** PART 2 ****" << std::endl;
    std::cout << "Hpos: " << hpos << " Depth: " << depth << std::endl;
    std::cout << "Product: " << hpos * depth << std::endl;
}

Command parseCommand(const std::string &cmd)
{
    if (cmd == "forward") {
        return FORWARD;
    } else if (cmd == "up") {
        return UP;
    } else if (cmd == "down") {
        return DOWN;
    } else {
        throw std::invalid_argument("Invalid command!");
    }
}
