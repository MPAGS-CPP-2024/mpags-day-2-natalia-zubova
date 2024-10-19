#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    
    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFileName{""};
    std::string outputFileName{""};
    bool encrypt{false};
    size_t key{0};
    std::string outputText{""};

    // Process command line arguments
    processCommandLine(
        cmdLineArgs,
        helpRequested,
        versionRequested,
        inputFileName,
        outputFileName,
        encrypt,
        key
    );

    std::ifstream inputFile {inputFileName};
    std::ofstream outputFile {outputFileName};

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    if (!inputFile.good()) {
        std::cerr << "Input file not found or broken, using stdin\n";
        // loop over each character from user input
        while (std::cin >> inputChar) {
            // inputText += transformChar(inputChar);
            inputText += inputChar;
        }
    }
    else {
        // loop over each character from input file
        std::cout << "Using input file '" << inputFileName << "'\n";
        while (inputFile >> inputChar) {
            // inputText += transformChar(inputChar);
            inputText += inputChar;
        }
    }    
    outputText = runCaesarCipher(inputText, key, encrypt);

    // testing that cipher works correctly
    // encrypt = not encrypt;
    // outputText = runCaesarCipher(outputText, key, encrypt);
    
    // Print out the transliterated text if output file is not specified 
    // or write to file
    if (!outputFile.good()) {
        std::cerr << "Output file not found or broken, using stdout\n";
        std::cout << outputText << std::endl;
    }
    else {
        outputFile << outputText << std::endl;
        std::cout << "Output written to file '" << outputFileName << "'\n";
    }

    // close files 
    inputFile.close();
    outputFile.close();

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}