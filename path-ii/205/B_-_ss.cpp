/** 
 * Sarievo.
 * URL: https://atcoder.jp/contests/abc066/tasks/abc066_b
 */

#include <bits/stdc++.h>
using namespace std;
/** ETC    */
using ll=long long;
#define int ll
/** VECTOR */
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using vi=vc<int>;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
/** PAIR   */
using pi=pair<int,int>;
#define mp make_pair
#define a first
#define b second
/** METHOD */
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename X> inline X abs(const X& a) {return (a<0?-a:a);}
template<typename X> inline X sqr(const X& a) {return (a*a);}
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b) // i[0-b]
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i[b-0]
#define foreach(it,a) for(__typeof((a).begin())it=(a).begin();it!=(a).end();it++)
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
/** DEBUG  */
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"{"<<p.a<<","<<p.b<<"}";}
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){os<<"{";for(auto e:v)os<<e<<",";return os<<"}";}
 
void f() {
    string s; cin >> s;
    int n = s.size();
    int R = n % 2 == 1 ? n - 1 : n - 2;
    while (R) {
        // cout << "found " << s.substr(0, R) << " at [:" << R << "]"<< endl;
        int M = R/2;
        if (s[0] == s[M]) {
            bool valid = true;
            rep(i, M) {
                if (s[i] != s[M+i]) {
                    // cout << "chking " << s[i] << ":" << i << " against " << s[M+i] << ":" << M+i << endl;
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cout << R << endl;
                return;
            }
        }
        R -= 2;
    }
}

signed main() {
    IOS;
    int T=1;
    // cin >> T;
    while (T--) {
        f();
    }
}