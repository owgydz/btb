#include <iostream>
#include <string>
#include <cstdlib>
#include "cli.h"
#include "../btbh/interpreter.h"
#include "../btbh/dependency.h"
#include "../btbh/runner.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Missing command." << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "build") {
        // Parse and build the project
        std::cout << "Starting build process..." << std::endl;
        BTB::Interpreter interpreter;
        if (!interpreter.parseFile("build.berg")) {
            std::cerr << "Error: Failed to parse build.berg." << std::endl;
            return 1;
        }

        BTB::DependencyManager dependencyManager;
        if (!dependencyManager.resolveDependencies(interpreter.getSources())) {
            std::cerr << "Error: Dependency resolution failed." << std::endl;
            return 1;
        }

        BTB::Runner runner;
        if (!runner.runBuildCommand(interpreter.getBuildCommand())) {
            std::cerr << "Error: Build failed." << std::endl;
            return 1;
        }

        std::cout << "Build completed successfully." << std::endl;
    } else if (command == "help") {
        BTB::CLI::showHelp();
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}
