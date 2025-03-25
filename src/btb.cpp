#include <iostream>
#include <string>
#include <cstdlib>
#include "cli.h"
#include "../btbh/inter.h"
#include "../btbh/depend.h"
#include "../btbh/runner.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Missing command." << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "build") {
        std::string config = (argc > 2) ? argv[2] : "default";
        BTB::CLI::buildWithConfig(config);
    } else if (command == "visualize") {
        BTB::CLI::visualizeDependencies();
    } else if (command == "help") {
        BTB::CLI::showHelp();
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}
