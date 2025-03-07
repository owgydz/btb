#include "../btbh/runner.h"
#include <iostream>
#include <cstdlib>

namespace BTB {

bool Runner::runBuildCommand(const std::string& command) {
    logBuildStep("Running build command: " + command);
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error: Build failed with command: " << command << std::endl;
        return false;
    }
    logBuildStep("Build completed successfully.");
    return true;
}

void Runner::logBuildStep(const std::string& step) {
    std::cout << "[BTB Build Log] " << step << std::endl;
}

} // namespace BTB
