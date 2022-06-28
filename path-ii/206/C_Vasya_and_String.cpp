/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/676/C
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

int n, k;
string s;

int find_max_by_char(char ch) {
    int max_length_a=0;
    int cur_length_a=0;
    deque<int> b_pos;
    int limit = k;
    rep(i,n) {
        if (s[i]==ch) {
            cur_length_a++;
            chmax(max_length_a,cur_length_a);
        } else {
            if (limit) {
                limit--;
                cur_length_a++;
                chmax(max_length_a,cur_length_a); // chmax, still
                b_pos.push_back(i);
            } else {
                if (b_pos.empty()) {
                    cur_length_a=0;
                } else {
                    int first_b=b_pos.front();
                    b_pos.pop_front();
                    cur_length_a=i-first_b;
                    chmax(max_length_a,cur_length_a); // chmax, still
                    b_pos.push_back(i);
                }
            }
        }
    }
    return max_length_a;
}

void f() {
    cin >> n >> k >> s;

    // select (a)
    int max_length_a=find_max_by_char('a');
    // select (b)
    int max_length_b=find_max_by_char('b');

    cout << max(max_length_a,max_length_b) << endl;
}