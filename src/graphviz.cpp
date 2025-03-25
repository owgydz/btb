#include <cstdlib>
#include <iostream>

void generateGraphImage(const std::string& dotFile, const std::string& outputImage) {
    std::string command = "dot -Tpng " + dotFile + " -o " + outputImage;
    if (system(command.c_str()) == 0) {
        std::cout << "Graph image generated: " << outputImage << "\n";
    } else {
        std::cerr << "Failed to generate graph image.\n";
    }
}
