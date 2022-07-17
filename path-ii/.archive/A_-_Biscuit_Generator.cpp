#include <iostream>
using namespace std;

int main() {
    int a, b, t;
    cin >> a >> b >> t;

    int interval = t / a;
    cout << interval * b;

    return 0;
}