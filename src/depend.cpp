#include "../btbh/depend.h"
#include <iostream>
#include <sys/stat.h>

namespace BTB {

bool DependencyManager::resolveDependencies(const std::vector<std::string>& sources) {
    for (const auto& source : sources) {
        std::cout << "Checking dependency for source: " << source << std::endl;
    }
    return true;
}

bool DependencyManager::needsRebuild(const std::vector<std::string>& sources, const std::string& target) {
    time_t targetTime = getFileModificationTime(target);
    for (const auto& source : sources) {
        time_t sourceTime = getFileModificationTime(source);
        if (sourceTime > targetTime) {
            return true;  // Source file is newer than the target
        }
    }
    return false;
}

time_t DependencyManager::getFileModificationTime(const std::string& filePath) {
    struct stat fileStat;
    if (stat(filePath.c_str(), &fileStat) != 0) {
        std::cerr << "Error: Could not get modification time for file " << filePath << std::endl;
        return 0;
    }
    return fileStat.st_mtime;
}

} // namespace BTB
