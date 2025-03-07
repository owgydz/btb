#ifndef BTB_CLI_H
#define BTB_CLI_H

#include <string>

namespace BTB {
namespace CLI {

void showHelp();
void showCommandHelp(const std::string& command);
void build();
void status();
void clean();
void version();

} // namespace CLI
} // namespace BTB

#endif // BTB_CLI_H
