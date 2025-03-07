#include "cli.h"
#include <iostream>

namespace BTB {
namespace CLI {

void showHelp() {
    std::cout << "Usage: btb <command>\n"
              << "Commands:\n"
              << "  build    - Build the project\n"
              << "  help     - Show this help message\n"
              << "  status   - Check status of build\n"
              << "  clean    - Clean build artifacts\n"
              << "  version  - Show version\n"
              << "Use 'btb <command> help' for more details on each command.\n";
}

void showCommandHelp(const std::string& command) {
    if (command == "build") {
        std::cout << "build: Builds the project from the .berg file.\n";
        std::cout << "Usage: btb build\n";
    } else if (command == "help") {
        std::cout << "help: Shows help information.\n";
        std::cout << "Usage: btb help\n";
    } else {
        std::cout << "Unknown command: " << command << "\n";
    }
}

} // namespace CLI
} // namespace BTB
