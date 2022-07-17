#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define x  first
#define y  second
#define pb push_back
#define mp make_pair
#define len(a) int((a).size())
// #define mset(a, val) memset(a, val, sizeof (a)) // ??
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define afor(i, n) for(int i = 0; i < int(n); i++)
#define dfor(i, n) for(int i = int(n - 1); i >= 0; i--)
#define ffor(i, a, b) for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
//======================================================

int n;
vector<int> a;
map<int, int> fmap;

bool read() {
    cin >> n;
    a = vector<int>(n);
    afor(i, n) {
        cin >> a[i];
        fmap[a[i]]++;
    }
    return true;
}

void solve() {
    assert(read());
    vector<int> fq;
    vector<pair<int,int>> values;
    for (pair<int,int> p : fmap) {
        values.push_back(p);
    }
    sort(all(values));
    reverse(all(values));
    for (int i = 0; i < (int)values.size(); i++) {
        fq.push_back(values[i].second);
    }

    // cout << "s arr: ";
    // afor(i, n) cout << a[i] << (i==n-1?"":",");
    // cout << endl;
    // cout << "f arr: ";
    // afor(i, (int)fq.size()) cout << fq[i] << (i==(int)fq.size()-1?"":",");
    // cout << endl;
    
    vector<int> m(3,0);
    ull sum = 0;
    for (int i = 0; i < (int)fq.size()-1; i++) { // ignore the last case
        if (m[0] == 0) {
            m[0] = fq[i];
            sum += fq[i];
        } else if (m[1] <= m[0]) {
            m[1] += fq[i];
            sum += fq[i];
        } else {
            if ((sum+fq[i]) > (n/2)) break;
            m[2] += fq[i];
            sum += fq[i];
        }
    }
    // cout << "raw: " << m[0] << "," << m[1] << "," << m[2] << endl;

    if ((!m[0]||!m[1]||!m[2])||(m[0]>=m[1]||m[0]>=m[2])) {
        cout << "0 0 0" << endl;
    } else {
        cout << m[0] << " " << m[1] << " " << m[2] << endl;
    }
    fmap.clear();
}

int main()
{
    fast_cin;
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
