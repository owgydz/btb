#include "../btbh/runner.h"
#include "../btbh/depend.h" 
#include <iostream>
#include <cstdlib>
#include <filesystem>

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

bool Runner::executeBuild(const std::string& command, const std::string& target) {
    logBuildStep("Starting build process for target: " + target);
    
    if (!preBuildChecks({})) {
        std::cerr << "Pre-build checks failed." << std::endl;
        return false;
    }

    if (runBuildCommand(command)) {
        logBuildStep("Build for " + target + " completed successfully.");
        return true;
    } else {
        logBuildStep("Build for " + target + " failed.");
        return false;
    }
}

bool Runner::skipUnchangedBuildSteps(const std::vector<std::string>& sources, const std::string& target) {
    DependencyManager depManager;
    if (depManager.isBuildUpToDate(sources, target)) {
        std::cout << "Skipping build: Target is up-to-date.\n";
        return true;
    }
    return false;
}

bool Runner::cleanBuildArtifacts() {
    try {
        std::filesystem::remove_all("build"); // Assuming "build" is the directory for build artifacts
        logBuildStep("Build artifacts cleaned successfully.");
        return true;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error cleaning build artifacts: " << e.what() << std::endl;
        return false;
    }
}

bool Runner::preBuildChecks(const std::vector<std::string>& sources) {
    for (const auto& source : sources) {
        if (!std::filesystem::exists(source)) {
            std::cerr << "Pre-build check failed: Missing source file " << source << std::endl;
            return false;
        }
    }
    logBuildStep("Pre-build checks passed.");
    return true;
}

} // namespace BTB
