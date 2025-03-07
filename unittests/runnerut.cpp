#include "runner.h"
#include <gtest/gtest.h>
#include <cstdlib>
#include <iostream>

namespace BTB {

TEST(RunnerTest, RunBuildCommand) {
    Runner runner;
    std::string command = "echo 'Building project'";
    
    // Use a valid command that simply prints a message
    ASSERT_TRUE(runner.runBuildCommand(command));
}

TEST(RunnerTest, FailBuildCommand) {
    Runner runner;
    std::string command = "nonexistentcommand";

    // Simulate a failed command
    ASSERT_FALSE(runner.runBuildCommand(command));
}

}  // namespace BTB
