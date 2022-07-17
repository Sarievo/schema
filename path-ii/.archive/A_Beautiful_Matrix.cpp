#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    int y;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int e;
            cin >> e;
            if (e == 1) {
                x = i;
                y = j;
            }
        }
    }
    cout << abs(2 - x) + abs(2 - y);
}