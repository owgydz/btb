#include "cli.h"
#include <gtest/gtest.h>
#include <sstream>

namespace BTB {
namespace CLI {

TEST(CliTest, ShowHelp) {
    std::ostringstream output;
    std::streambuf* orig_buf = std::cout.rdbuf(output.rdbuf());

    showHelp();

    std::cout.rdbuf(orig_buf);
    std::string result = output.str();
    ASSERT_NE(result.find("Usage: btb"), std::string::npos);
}

TEST(CliTest, ShowCommandHelp) {
    std::ostringstream output;
    std::streambuf* orig_buf = std::cout.rdbuf(output.rdbuf());

    showCommandHelp("build");

    std::cout.rdbuf(orig_buf);
    std::string result = output.str();
    ASSERT_NE(result.find("build:"), std::string::npos);
}

} // namespace CLI
} // namespace BTB
