#include <iostream>
#include <string>
#include <random>
#include <ctime>

// Function to generate a random password
std::string GeneratePassword(int length, bool useLowercase, bool useUppercase, bool useDigits, bool useSpecialChars) {
    const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digitChars = "0123456789";
    const std::string specialChars = "!@#$%^&*()_+";

    std::string charset = "";

    if (useLowercase) charset += lowercaseChars;
    if (useUppercase) charset += uppercaseChars;
    if (useDigits) charset += digitChars;
    if (useSpecialChars) charset += specialChars;

    if (charset.empty()) {
        return "Error: No character set selected.";
    }

    const int charsetSize = charset.length();
    std::string password;
    
    std::mt19937_64 rng(std::time(nullptr)); // Initialize a random number generator with the current time

    for (int i = 0; i < length; ++i) {
        int randomIndex = rng() % charsetSize;
        password += charset[randomIndex];
    }

    return password;
}

int main() {
    int passwordLength;
    bool useLowercase, useUppercase, useDigits, useSpecialChars;

    std::cout << "Enter the length of the password: ";
    std::cin >> passwordLength;

    if (passwordLength <= 0) {
        std::cerr << "Error: Password length should be greater than 0." << std::endl;
        return 1;
    }

    std::cout << "Include lowercase characters? (1/0): ";
    std::cin >> useLowercase;

    std::cout << "Include uppercase characters? (1/0): ";
    std::cin >> useUppercase;

    std::cout << "Include digits? (1/0): ";
    std::cin >> useDigits;

    std::cout << "Include special characters? (1/0): ";
    std::cin >> useSpecialChars;

    std::string password = GeneratePassword(passwordLength, useLowercase, useUppercase, useDigits, useSpecialChars);
    
    if (password.find("Error:") != std::string::npos) {
        std::cerr << password << std::endl;
        return 1;
    }

    std::cout << "Generated Password: " << password << std::endl;

    return 0;
}
