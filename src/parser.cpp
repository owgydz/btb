#include "../btbh/parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

// Parse the Berg file and extract target, sources, and command.
bool BergParser::parseFile(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }

    std::string line;
    bool targetFound = false;
    bool sourcesFound = false;
    bool commandFound = false;

    while (std::getline(file, line)) {
        // Remove leading and trailing spaces
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        if (line.empty()) {
            continue;  // Skip empty lines
        }

        if (!targetFound && line.find("target:") == 0) {
            target = line.substr(7); // Extract target value (after "target:")
            targetFound = true;
        }
        else if (!sourcesFound && line.find("sources:") == 0) {
            sourcesFound = true;
            std::stringstream ss(line.substr(8)); // Extract sources (after "sources:")
            std::string source;
            while (std::getline(ss, source, ',')) {
                sources.push_back(source); // Add each source to the list
            }
        }
        else if (!commandFound && line.find("command:") == 0) {
            command = line.substr(8); // Extract command (after "command:")
            commandFound = true;
        }
    }

    file.close();

    return targetFound && sourcesFound && commandFound;
}

// Return the target value.
std::string BergParser::getValue(const std::string& key) const {
    if (key == "target") {
        return target;
    }
    if (key == "command") {
        return command;
    }
    return "";
}

// Return the list of sources.
std::vector<std::string> BergParser::getSources() const {
    return sources;
}

// Return the build command.
std::string BergParser::getCommand() const {
    return command;
}
