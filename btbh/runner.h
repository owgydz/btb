#ifndef BTB_RUNNER_H
#define BTB_RUNNER_H

#include <string>

namespace BTB {

class Runner {
public:
    bool runBuildCommand(const std::string& command);
    void logBuildStep(const std::string& step);
};

} // namespace BTB

#endif // BTB_RUNNER_H
