// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

// Example 1:

// Input: "Hello"
// Output: "hello"
// Example 2:

// Input: "here"
// Output: "here"
// Example 3:

// Input: "LOVELY"
// Output: "lovely"

#include <string>

std::string toLowerCase(std::string str) {
    for (auto &c : str)
        if (c >= 65 && c <= 90)
            c += 32;

    return str;
}