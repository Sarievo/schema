/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1700/problem/C
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
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;} // if a < b, a is replaced by b
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;} // if a > b, a is replaced by b
template<typename X> inline X abs(const X& a) {return (a<0?-a:a);}
template<typename X> inline X sqr(const X& a) {return (a*a);}
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b) // i[0-b), go to range asc
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i(b-0], go to range desc
template<class t> void fill(vc<t>& v, int inc=0) {iota(all(v),inc);}
#define acc(a) accumulate(all(a),int(0)) //...
//!<---------- end of define !<----------------------------
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){os<<"{";for(auto e:v)os<<e<<":";return os<<"}";}
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"{"<<p.a<<":"<<p.b<<"}";}
//!<---------- end of debug !<-----------------------------
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void f();
signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------

void f() {
    int n; cin >> n;
    vi a(n); for (auto &x : a) cin >> x;
    /* 
    we can add all i and reduce all i in one operation
    we may want to reduce everything to equillibium
    calculate the minimum operations needed to make all numbers equal, by reducing [0,r] [l,n-1] by 1

    if the numbers are ascending, we can apply [0,n] [1,n]... etc
    if the numbers are descending, we can apply [0,1] [0,2].. etc
    does two pointers matter?

    if the numbers are not ascending nor descending.
    calcute the minimum steps to make it desc at left side and asc at right side by some pivot?
    -4 4 -4 4 -> -4 -4 -12 -4 (8) -> -12 -12 -12 -4 (16) -> -12 -12 -12 -12 (24) -> 0 0 0 0 (36)

    how about making every i desc or asc?'  it's d, now we can apply some prefix to make it all equals
   d 4 -4 4 -4 -> 4 -4 -4 -12(8)              -> -4 -12 -12 -12 (16) -> -12 -12 -12 -12 (24) -> all 0 (36)
   a        -> -4 -12 -4 -4(8) -> -12 -12 -4 -4(16) ->[pf] -12 -12 -12 -12 (24) -> 36
   
    e.g.  1 5 9 -2 8 -9 
    the diff is 9--9(18),
        we can apply some straight forward dp to calculate the cost of making a/d in o(n)
                          4 8      18       from R to L:  28      17
    d: 1,5,9,-2,8,-9 -> 1,1,1,-10,-10,-27(18) -> -27,-27,-27,-27,-27,-27(28) -> 18+28+27 = 73
    a:  -> -27,-23,-19,-19,-9,-9(28) -> -27 * 6 (18) -> 28 + 18 + 27 = 73
                    28     17
we can reuse fucntion
                            5    14         10
    1 -2 3 -4 5 -> d: 1 -2 -2 -9 -9 -> a: -9 *5 -> 14 + 10 + 9 -> 33
     */
    if (n ==1) {
        cout << abs(a[0]) << endl;
        return;
    }

    int reduce = 0;
    for (int i = 0; i < n-1; i++) { // make d
        int& x = a[i];
        int& y = a[i+1];
        y -= reduce;
        if (y > x) {
            reduce += y - x;
            y -= (y - x);
        }
    }
    // cout <<"d:";
    // cout << a << endl;
    int reduce2 = 0;
    for (int i = n-1; i > 0; i--) {
        int& x = a[i-1];
        int& y = a[i];
        x -= reduce2;
        if (x > y) {
            reduce2 += (x - y);
            x -= (x - y);
        }
    }
    // cout <<"a:";
    // cout << a << endl;
    // cout << endl;
    cout << (reduce + reduce2 + abs(a[0])) << endl;


    // reverse(all(a)); // i'm lazy to write another one

    // int inc = 0;
    // for (int i = 0; i < n-1; i++) { // make d
    //     int& x = a[i];
    //     int& y = a[i+1];
    //     y -= inc;
    //     if (y > x) {
    //         inc += y - x;
    //         y -= inc;
    //     }
    // }
    
    // cout << a << endl;
    // cout << inc << endl;

    // int increase = 0;
    // int prev = abs(a[n-1]);
    // for (int i = n-1; i >= 1; i--) {
    //     if (a[i] != a[i+1]) {
    //         increase +=abs(a[i]-a[i-1])-increase;
    //     }
    // }

    // for (int i = n-1; i >= 1; i--) { // make a
    //     int& x = a[i];
    //     int& y = a[i-1];
    //     cout << x << ":" << y << endl;
    //     y -= increse;
    //     if (x < y) {
    //         increse += (y - x);
    //         y -= increse;
    //     }
    // }
    // cout <<"a:";
    // cout << a << endl;

    // cout << reduce + inc + a[0] << endl;
    // cout << reduce + increse + abs(a[n-1]) << endl;
}