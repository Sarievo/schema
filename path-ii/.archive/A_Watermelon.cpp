#include <iostream>

int main() {
    int input;
    std::cin >> input;
    if (input > 3 && input % 2 == 0) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}