#include "dependency.h"
#include <gtest/gtest.h>
#include <fstream>
#include <ctime>

namespace BTB {

TEST(DependencyManagerTest, NeedsRebuildIfSourceModified) {
    std::ofstream sourceFile("source.cpp");
    sourceFile << "int main() {}";
    sourceFile.close();

    std::ofstream targetFile("target.o");
    targetFile << "void target() {}";
    targetFile.close();

    DependencyManager depManager;
    std::vector<std::string> sources = {"source.cpp"};
    ASSERT_TRUE(depManager.needsRebuild(sources, "target.o"));

    // Clean up
    std::remove("source.cpp");
    std::remove("target.o");
}

TEST(DependencyManagerTest, NoRebuildIfTargetIsNewer) {
    std::ofstream sourceFile("source.cpp");
    sourceFile << "int main() {}";
    sourceFile.close();

    std::ofstream targetFile("target.o");
    targetFile << "void target() {}";
    targetFile.close();

    // Change the target file's timestamp to be newer
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::ofstream newTargetFile("target.o");
    newTargetFile << "updated target";
    newTargetFile.close();

    DependencyManager depManager;
    std::vector<std::string> sources = {"source.cpp"};
    ASSERT_FALSE(depManager.needsRebuild(sources, "target.o"));

    // Clean up
    std::remove("source.cpp");
    std::remove("target.o");
}

}  // namespace BTB
