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

class Problem2Solver
{
private:
    OrderedPairs *commands;
    static Command parseCommand(const std::string &cmd);
    void loadFromFile(std::fstream &infile);

public:
    void doPart1() const;
    void doPart2() const;

    Problem2Solver(std::fstream &infile);
    ~Problem2Solver();
};

int main(int argc, char **argv)
{
    // File stream
    std::fstream infile("in2.txt");

    Problem2Solver solver{infile};

    solver.doPart1();
    solver.doPart2();

    return EXIT_SUCCESS;
}

Problem2Solver::Problem2Solver(std::fstream &infile)
{
    commands = new OrderedPairs{};
    this->loadFromFile(infile);
}

Problem2Solver::~Problem2Solver()
{
    delete commands;
}

void Problem2Solver::loadFromFile(std::fstream &infile)
{
    std::string commandString;
    int amount{0};

    while (infile >> commandString >> amount)
    {
        // Write the construction of the pair explicitly for practice
        // but push_back (insert with a Map) would probably accept a list {}
        this->commands->push_back(std::pair<Command, int>{this->parseCommand(commandString), amount});
    }
}

void Problem2Solver::doPart1() const
{
    long long hpos{0}, depth{0};
    for (const auto &pair : *(this->commands))
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

void Problem2Solver::doPart2() const
{
    long long hpos{0}, depth{0}, aim{0};
    for (const auto &pair : *(this->commands))
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

Command Problem2Solver::parseCommand(const std::string &cmd)
{
    if (cmd == "forward")
    {
        return FORWARD;
    }
    else if (cmd == "up")
    {
        return UP;
    }
    else if (cmd == "down")
    {
        return DOWN;
    }
    else
    {
        throw std::invalid_argument("Invalid command!");
    }
}
