#ifndef BTB_CLI_H
#define BTB_CLI_H

#include <string>

namespace BTB {
namespace CLI {

void showHelp();
void showCommandHelp(const std::string& command);

} // namespace CLI
} // namespace BTB

#endif // BTB_CLI_H
