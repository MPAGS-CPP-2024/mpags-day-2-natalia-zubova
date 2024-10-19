#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(
    const std::string& inputText,
    const size_t key,
    const bool encrypt
)
{
    // Create the alphabet container and output string
    const std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::size_t alphabetSize{alphabet.size()};
    std::string outputString{""};
    
    // Loop over the input text
    // For each character find the corresponding position in the alphabet
    // Apply the shift (+ve or –ve depending on encrypt/decrypt)
    // to the position, handling correctly potential wrap-around
    // Determine the new character and add it to the output string
    for (const char& inputLetter: inputText)
    {   
        if (encrypt){
            outputString += alphabet[(alphabet.find(inputLetter) + key) % alphabetSize];
        }
        else{
            outputString += alphabet[(alphabet.find(inputLetter) + alphabetSize - key) % alphabetSize];
        }
    }
    
    // Finally (after the loop), return the output string
    return outputString;
}
