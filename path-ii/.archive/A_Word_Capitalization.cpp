#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;
    if (a[0] > 'Z')
        a[0] -= 'a' - 'A';
    cout << a;
}