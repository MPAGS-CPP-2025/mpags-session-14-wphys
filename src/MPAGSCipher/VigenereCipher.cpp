#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <algorithm>

/**
 * \file VigenereCipher.cpp
 * \brief Contains the implementation of the VigenereCipher class
 */

VigenereCipher::VigenereCipher(const std::string& key)
{
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    // Store the key
    key_ = key;
    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);
    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));
    // Check if the key is empty and replace with default if so
    if (key_.empty()) {
        key_ = "KEY";
    }
    // loop over the key
    for (const auto& c : key_) {
        // Find the letter position in the alphabet
        std::size_t position{Alphabet::alphabet.find(c)};
        // Create a CaesarCipher using this position as a key
        CaesarCipher caesarCipher{position};
        // Insert a std::pair of the letter and CaesarCipher into the lookup
        charLookup_.insert(std::make_pair(c, caesarCipher));
    }
}
#include <iostream>
std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    std::string outputText;
    outputText.reserve(inputText.size());
    // For each letter in input:
    for (std::size_t i{0}; i < inputText.size(); ++i) {
        char c{inputText[i]};
        // Find the corresponding letter in the key,
        // repeating/truncating as required
        char keyChar{key_[i % key_.size()]};
        // Find the Caesar cipher from the lookup
        const CaesarCipher& caesarCipher{charLookup_.at(keyChar)};
        // Run the (de)encryption
        char newChar{
            caesarCipher.applyCipher(std::string(1, c), cipherMode)[0]};
        // Add the result to the output
        outputText += newChar;
    }
    return outputText;
}
