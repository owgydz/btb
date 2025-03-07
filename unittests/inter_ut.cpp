#include "interpreter.h"
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>

namespace BTB {

TEST(InterpreterTest, ParseValidBergFile) {
    // Create a temporary valid build.berg file
    std::ofstream buildFile("test.berg");
    buildFile << "target: my_program\n"
              << "source: main.cpp utils.cpp\n"
              << "command: g++ -o my_program main.cpp utils.cpp\n";
    buildFile.close();

    Interpreter interpreter;
    ASSERT_TRUE(interpreter.parseFile("test.berg"));

    std::vector<std::string> sources = interpreter.getSources();
    ASSERT_EQ(sources.size(), 2);
    ASSERT_EQ(sources[0], "main.cpp");
    ASSERT_EQ(sources[1], "utils.cpp");

    std::string command = interpreter.getBuildCommand();
    ASSERT_EQ(command, "g++ -o my_program main.cpp utils.cpp");

    std::vector<std::string> targets = interpreter.getTargets();
    ASSERT_EQ(targets.size(), 1);
    ASSERT_EQ(targets[0], "my_program");

    // Clean up
    std::remove("test.berg");
}

TEST(InterpreterTest, ParseInvalidBergFile) {
    // Create an invalid build.berg file (missing command)
    std::ofstream buildFile("invalid.berg");
    buildFile << "target: my_program\n"
              << "source: main.cpp utils.cpp\n";
    buildFile.close();

    Interpreter interpreter;
    ASSERT_FALSE(interpreter.parseFile("invalid.berg"));

    // Clean up
    std::remove("invalid.berg");
}

}  // namespace BTB
