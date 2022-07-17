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


int main() {
    fast_cin();
    int n;
    cin >> n;

    int twos = 0;
    int threes = 0;

    unordered_map<int, int> fmap;
    afor(i, n) {
        int tmp;
        cin >> tmp;
        fmap[i]++;
        int val = fmap[i];
        if (val > 1) {
            twos++;
            if (val > 2) {
                threes++;
            }
        }
    }

    twos = twos - threes;
    int ones = n - twos - threes;
    
    /* 
    10*9*8/3*2*1
    2*1*1

    choose at pos:
        distinct keys, dk-1, dk-2
        *distinct codes *dc  *dc

    divided by 3*2*1??
    */
    if (ones + twos + threes < 3) {
        cout << 0 << endl;
    } else {
        ll ans = n*(n-1)*(n-2)/(3*2*1);
        cout << ans << endl;
    }
}