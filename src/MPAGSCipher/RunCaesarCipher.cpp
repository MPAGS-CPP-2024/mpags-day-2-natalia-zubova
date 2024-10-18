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
    std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string outputString{""};
    
    // Loop over the input text
    for (const char& inputLetter: inputText)
    {   
        if (encrypt){
            outputString += alphabet[(alphabet.find(inputLetter) + key) % 26];
        }
        else{
            outputString += alphabet[(alphabet.find(inputLetter) - key) % 26];
        }
        
    }
    
    // For each character find the corresponding position in the alphabet
    
    
    // Apply the shift (+ve or –ve depending on encrypt/decrypt)
    // to the position, handling correctly potential wrap-around
    
    
    // Determine the new character and add it to the output string
    
    
    // Finally (after the loop), return the output string

    return outputString;
}
