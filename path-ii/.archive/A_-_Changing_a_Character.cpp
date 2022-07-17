#include <iostream>
#include <string>

int main() {
    int n;
    int k;
    std::string s;

    std::cin >> n;
    std::cin >> k;
    std::cin >> s;

    s[k - 1] -= 'A' - 'a';
    std::cout << s;
    return 0;
}