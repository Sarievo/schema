/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/75/C
 */

#include <bits/stdc++.h>
using namespace std;
//!<---------- start of define !<--------------------------
using ll=long long;
// #define int ll
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
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;} // if a < b, a is replaced by b
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;} // if a > b, a is replaced by b
template<typename X> inline X abs(const X& a) {return (a<0?-a:a);}
template<typename X> inline X sqr(const X& a) {return (a*a);}
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b) // i[0-b], go to range asc
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i[b-0], go to range desc
template<class t> void fill(vc<t>& v, int inc=0) {iota(all(v),inc);}
#define acc(a) accumulate(all(a),int(0)) //...
//!<---------- end of define !<----------------------------
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){os<<"{";for(auto e:v)os<<e<<":";return os<<"}";} // ease for debugging vectors
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"{"<<p.a<<":"<<p.b<<"}";} // ease for debugging pairs
//!<---------- end of debug !<-----------------------------
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void f();
signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

vector<pair<int, int> > factors;
void getFactors(int n) {
    factors.clear();
    int d = 1;
    for (int i = 2; i * i <= n; i += d, d = 2)
        if (n % i == 0) {
            factors.push_back(make_pair(i, 0));
            while (n % i == 0) {
                n /= i;
                factors.back().second++;
            }
        }
    if (n != 1)
        factors.push_back(make_pair(n, 1));
}
 
vector<int> divisors;
void getDivisors(int ind = 0, int res = 1) {
    if (ind == (int) factors.size()) {
        divisors.push_back(res);
        return;
    }
    for (int i = 0; i <= factors[ind].second; i++) {
        getDivisors(ind + 1, res);
        res *= factors[ind].first;
    }
}

void f() {
    int a, b, n;
    scanf("%d", &a);
    getFactors(a);
    getDivisors();
    vector<int> d1 = divisors;
    scanf("%d", &b);
    getFactors(b);
    divisors.clear();
    getDivisors();
    vector<int> d2 = divisors;
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    vector<int> cd;
    set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), inserter(cd,
            cd.begin()));
    scanf("%d", &n);
    int low, high, ind;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &low, &high);
        ind = upper_bound(cd.begin(), cd.end(), high) - cd.begin();
        ind--;
        if (ind == -1 || cd[ind] < low)
            printf("-1\n");
        else
            printf("%d\n", cd[ind]);
    }
}