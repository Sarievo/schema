#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n = 0; // n students
    int m = 0; // m problems
    cin >> n >> m;
 
    int tt[1000][5] = {0}; // init 2d array with 0
    while (n--) {
        string s;
        cin >> s;
 
        for (int i = 0; i < m; i++) {
            tt[i][s[i] - 'A']++;
        }
    }
 
    int total = 0;
    for (int i = 0; i < m; i++) {
        int score;
        cin >> score;
        int maxOcc = 0;
        for (int sc : tt[i]) {
            if (sc > maxOcc) maxOcc = sc;
        }
        total += maxOcc * score;
    }
    cout << total;
}