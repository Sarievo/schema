#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define x first
#define y second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
#define afor(i, n)     for(int i = 0; i < int(n); i++)
#define dfor(i, n)     for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b)  for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 1e7 + 5;
const int INF = 2e9, MOD = 1e9+7;

int calcDist(vector<int> &occ) {
    int lastPos = -1;
    int cost = 0;

    // afor(i, 10) {
    //     cout << occ[i] << " ";
    // }
    // cout << endl;

    bool hasFinished = false;
    while (!hasFinished) {
        hasFinished = true;
        afor(i, 10) {
            int value = occ[i];
            if (!value) continue;
            else {
                hasFinished = false;
                if (lastPos == -1) {
                    cost = i;
                } else {
                    if (i == lastPos) {
                        cost += 10;
                    } else if (i > lastPos) {
                        int dist = (i-lastPos);
                        cost += dist;
                    } else {
                        int dist = (i+10)-lastPos;
                        cost += dist;
                    }
                }
                lastPos = i;
                occ[i]--;
            }
        }
    }
    return cost;
}

int main() {
    fast_cin();
    int n;
    cin >> n;
    /**
     * find the shortest path in all numbers
     * if numbers are identical print (n-1)*10
     * 
     * >> occurrences map
     * calc each number dist
     */
    
    vector<vector<int>> mmap(10, vector<int>(10, 0));
    afor(i, n) {
        string input;
        cin >> input;
        afor(x, 10) {
            int c = input[x] - '0';
            mmap[c][x]++;
        }
    }

    int minDist = 1e9;
    afor(i, 10) {
        int dist = calcDist(mmap[i]);
        if (dist < minDist) minDist = dist;
    }

    cout << minDist << endl;
}