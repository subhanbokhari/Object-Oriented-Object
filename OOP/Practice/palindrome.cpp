#include <iostream>
using namespace std;

int is_palindrome(string str) {
    // An empty string or a string with only one character is always a palindrome
    if (str.empty() || str.length() == 1) {
        return 1;
    }
    // Check if the first and last character are the same
    if (str[0] != str[str.length() - 1]) {
        return 0;
    }
    // Recursively check if the string between the first and last character is also a palindrome
    return is_palindrome(str.substr(1, str.length() - 2));
}

int main() {
    string str1 = "racecar";
    string str2 = "hello";
    string str3 = "a";
    string str4 = "";

    cout << str1 << " is a palindrome: " << is_palindrome(str1) << endl;
    cout << str2 << " is a palindrome: " << is_palindrome(str2) << endl;
    cout << str3 << " is a palindrome: " << is_palindrome(str3) << endl;
    cout << "An empty string is a palindrome: " << is_palindrome(str4) << endl;

    return 0;
}