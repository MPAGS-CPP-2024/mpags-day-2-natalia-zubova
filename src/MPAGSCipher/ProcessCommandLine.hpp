#ifndef PROCESSCOMMANDLINE_HPP
#define PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

bool processCommandLine(
    const std::vector<std::string>& cmdLineArgs,
    bool& helpRequested,
    bool& versionRequested,
    std::string& inputFile,
    std::string& outputFile,
    bool& encrypt,
    size_t& key
);

#endif // PROCESSCOMMANDLINE_HPP