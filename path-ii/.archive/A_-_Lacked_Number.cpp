#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int sum = 45;
    for (char c : s) {
        sum -= c - '0';
    }
    cout << sum;
}