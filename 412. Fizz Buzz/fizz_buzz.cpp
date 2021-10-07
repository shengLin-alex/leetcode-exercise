// Write a program that outputs the string representation of numbers from 1 to n.

// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.
// For numbers which are multiples of both three and five output “FizzBuzz”.

// Example:

// n = 15,

// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

#include <string>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i < n + 1; i++) {
        if (i % 15 == 0 && i >= 15) {
            res.push_back("FizzBuzz");
        } else if (i % 5 == 0 && i >= 5) {
            res.push_back("Buzz");
        } else if (i % 3 == 0 && i >= 3) {
            res.push_back("Fizz");
        } else {
            res.push_back(to_string(i));
        }
    }

    return res;
}