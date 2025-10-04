#include <string>
#include <iostream>

int main() {
    std::string s = "   hello world";

    s.erase(0, s.find_last_not_of(' '));

    std::cout << "[" << s << "]\n"; // prints "[hello world]"
}
