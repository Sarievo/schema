/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1700/problem/B
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

void add(string& s) {
    string t = "";
    for (int i = 0; i < s.size()-1; i++) {
        t.push_back('1');
    }
    t.push_back('2');

    bool curry = false;
    for (int i = s.size()-1; i >= 0; i--) {
        int a = s[i]-'0';
        int b = t[i]-'0';
        if (a + b + curry <= 9) {
            s[i] = '0'+(a + b + curry);
            curry = false;
        } else {
            s[i] = '0'+(a + b + curry - 10);
            curry = true;
        }
    }
    assert(curry == false); // we assume curry must be false at the last digit 
}

void f() {
    int n; cin >> n;
    assert(n >= 2);
    string s; cin >> s;

    string result = "";
    for (auto& x : s) {
        result.push_back(char(('9'-x+'0')));
    }
    if (s[0] < '9') {
        cout << result << endl;
    } else {
        add(result);
        cout << result << endl;
    }
    /* 
    now, if the number start with lesser then 9
        we can always fill the number to 9
        ie. 8999 -> fill to be 9999
            3591 -> 9999 ->[9-3][9-5][9-9][9-1]->6408
    but, if the number start with 9,
        we must fill it to the next significant digit
        ie. 999 -> 1XX1 (?)
        999 -> 1111 ? [2]
                1001
                we must fill it to the 1000
                999 -> 1000 = 001
                then we know we can lift 999 to 1111 by +112
                001 -> 112
            ie. 91257 -> 8742 -> 11112 -> 19854
                now we must calculate from the end and log qurry
                ...

        99 -> +12
     */
}