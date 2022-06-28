/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/250/d
 */

#include <bits/stdc++.h>
using namespace std;
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
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
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
    // cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

void f() {
	ll n, m, ax, bx;
	cin >> n >> m >> ax >> bx;
	vector<ll> a(n), b(m), c(m);
	cin >> a >> b >> c;
	a.push_back(1e18);
 
	pair<ll, ll> best = { 0,0 };
	long double bestl = 1e9;
	ll l = 0;
	ll dx = bx - ax;
	for (int i = 0; i < m; i++) {
		while (l < ((ll)a.size() - 2) && a[l + 1] * bx < b[i] * ax) l++;
		ll ay1 = a[l];
		ll ay2 = a[l + 1];
		ll dy1 = b[i] - a[l];
		ll dy2 = b[i] - a[l+1];
		long double res1 = sqrt((long double)(ax * ax) + (ay1 * ay1))
                         + sqrt((long double)(dx * dx) + (dy1 * dy1)) + c[i];
		long double res2 = sqrt((long double)(ax * ax) + (ay2 * ay2))
                         + sqrt((long double)(dx * dx) + (dy2 * dy2)) + c[i];
		if (res1 < bestl) {
			bestl = res1;
			best = { l + 1, i + 1 };
		}
		if (res2 < bestl) {
			bestl = res2;
			best = { l + 2, i + 1 };
		}
	}
	cout << best.first << " " << best.second << endl;
}