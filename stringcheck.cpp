#include<iostream>
#include<string>

bool stringCheck(const std::string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    if (stringCheck(str)) {
        std::cout << "The string contains only alphabetic characters.";
    } else {
        std::cout << "The string does not contain only alphabetic characters.";
    }

    return 0;
}
