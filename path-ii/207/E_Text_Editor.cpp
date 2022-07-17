/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1701/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    // https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<class t> using hashset=unordered_set<t,custom_hash>;
template<class t,class u> using hashmap=unordered_map<t,u,custom_hash>;
//!<---------- start of define !<--------------------------
using ll=long long;
#define int ll
using ull=unsigned long long;
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pi=pair<int,int>;
#define mp make_pair
#define a first
#define b second
using vi=vc<int>;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back
template<class t,class u> bool chmax(t&a,const u&b){return a<b?a=b,1:0;}
template<class t,class u> bool chmin(t&a,const u&b){return a>b?a=b,1:0;}
template<typename X> inline X abs(const X& a) {return (a<0?-a:a);}
template<typename X> inline X sqr(const X& a) {return (a*a);}
#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)    // [a,b)
#define rep(i,b) FOR(i,0,b)
#define DWN(i,a,b) for(int i=int(b)-1;i>=int(a);i--) // (b,a]
#define per(i,b) DWN(i,0,b)
template<class t> void asc(vc<t>& v, int inc=0) {iota(all(v),inc);}
#define acc(a) accumulate(all(a),int(0)) //...
//!<---------- end of define !<----------------------------
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template<typename T> istream& operator>>(istream& is, vc<T>&v){for(auto&e:v)is>>e;return is;}
template<typename T> ostream& operator<<(ostream& os, const vc<T>&v){for(auto&e:v)os<<e<<" ";return os;}
template<typename T> istream& operator>>(istream& is, pair<T,T>&v){is>>v.a>>v.b;return is;}
template<typename T> ostream& operator<<(ostream& os, const pair<T,T>&v){os<<v.a<<" "<<v.b;return os;}
//!<---------- end of IO !<-----------------------------
void f();
signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------
vi zf(const string &s) {
    int n = s.size();
    vi z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void f() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int ans = 1e9;
    bool bad = false;
    vi lpos(m), rpos(m);
    rep(i, m) {
        if (i > 0)
            lpos[i] = lpos[i-1]+1;
        else
            lpos[i] = 0;
        while (lpos[i]<n && s[lpos[i]]!=t[i])
            ++lpos[i];
        if (lpos[i] >= n) {
            bad = true;
            break;
        }
    }
    for (int i=m-1; i>=0; --i) {
        if (i+1 < m)
            rpos[i]=rpos[i+1]-1;
        else
            rpos[i]=n-1;
        while (rpos[i] >= 0 && s[rpos[i]]!=t[i])
            --rpos[i];
        if (rpos[i]<0) {
            bad = true;
            break;
        }
    }
    if (bad) {
        cout << -1 << endl;
        return;
    }
    for (int pos = 0; pos <= n; ++pos) {
        string tmp = s.substr(0, pos);
        reverse(all(tmp));
        tmp += "#" + t;
        reverse(tmp.begin() + pos + 1, tmp.end());
        vector<int> z = zf(tmp);
        for (int suf = 0; suf <= m; ++suf) {
            if (pos - suf < 0)
                continue;
            if (suf < m && rpos[suf] < pos)
                continue;
            if (suf - 1 >= 0 && lpos[suf - 1] > pos)
                continue;
            int rg = 0;
            if (suf != 0) {
                int sum = (pos - z[pos + 1 + m - suf]) + (pos - suf);
                rg = (sum != 0) + sum;
            } else
                rg = pos;
            ans = min(ans, (n - pos) + rg);
        }
    }
    cout << ans << endl;
}