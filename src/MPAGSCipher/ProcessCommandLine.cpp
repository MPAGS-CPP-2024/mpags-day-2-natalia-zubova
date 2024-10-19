#include<string>
#include<vector>
#include <iostream>
#include "ProcessCommandLine.hpp"

bool processCommandLine(
    const std::vector<std::string>& cmdLineArgs,
    bool& helpRequested,
    bool& versionRequested,
    std::string& inputFile,
    std::string& outputFile,
    bool& encrypt,
    size_t& key
)
{
    // ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    const std::size_t nCmdLineArgs{cmdLineArgs.size()};
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        } else if (cmdLineArgs[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                inputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                outputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-m") {
        //  mode of cipher: encrypt/decrypt
            if (i == nCmdLineArgs - 1) {
                    std::cerr << "[error] -m requires a cipher's mode argument"
                            << std::endl;
                    // exit main with non-zero return to indicate failure
                    return 1;
                }
            {
                if (cmdLineArgs[i + 1] == "encrypt")
                {
                    encrypt = true;
                }
                else if (cmdLineArgs[i + 1] == "decrypt")
                {
                    encrypt = false;
                }
                else
                {
                    std::cerr << "[error] -m argument accept only encrypt/decrypt modes"
                            << std::endl;
                    // exit main with non-zero return to indicate failure
                    return 1;
                }
            }
            ++i;
        } else if (cmdLineArgs[i] == "-k") {
            if (i == nCmdLineArgs - 1) {
                    std::cerr << "[error] -k argument requires a key argument"
                            << std::endl;
                    // exit main with non-zero return to indicate failure
                    return 1;
                }
            else
            {   
                key = std::stoul(cmdLineArgs[i + 1]);
                ++i;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << cmdLineArgs[i]
                      << "'\n";
            return 1;
        }
    }
    return 0;
}
