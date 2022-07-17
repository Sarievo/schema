// #include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int a, b, c;

    while (n--) {
        cin >> a >> b >> c;
        if ((a + b + c) >= 2)
            cnt++;
    }

    cout << cnt << endl;
    // return 0;
}