#include <bits/stdc++.h>
using namespace std;

// #define

string solve() {
    int n = 1;
    cin >> n;
    // int * a = new int[n];
    /*
    idea: log the best laptop and the worst laptop?
    */
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = vector<int>(2);
        cin >> a[i][0];
        cin >> a[i][1];
    }

    sort(a.begin(), a.end());
    int prevAnchor = -1;
    int prevBest = -1;
    for (int i = 0; i < n; i++) {
        if (prevAnchor != a[i][0] && prevBest > a[i][1])
            return "Happy Alex";
        prevAnchor = a[i][0];
        prevBest = max(prevBest, a[i][1]);
    }
    return "Poor Alex";
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        cout << solve() << endl;
    }
    return 0;
}
