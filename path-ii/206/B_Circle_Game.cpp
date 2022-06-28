/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1695/problem/B
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
if the pile is of odd number
 1 0 1
 0 1 0
the first player always wins because he can just remove the first pile to zero and the second player will eventually encounter it

 if the pile is of even number
 each player just remove the smallest one, then count sum, smaller one loses
 */
    if (n % 2 == 1) {
        cout << "Mike" << endl;
    } else {
        // the player can just remove the smallest amount of stones possible
        
        int min_m = a[0];
        int min_j = a[1];
        int id_m = 0;
        int id_j = 1;
        rep(i,n) {
            if (i % 2 == 0) {
                if (a[i] < min_m) {
                    min_m = a[i];
                    id_m = i;
                }
            } else {
                if (a[i] < min_j) {
                    min_j = a[i];
                    id_j = i;
                }
            }
        }

        if (min_m < min_j) {
            cout << "Joe" << endl;
        } else if (min_m > min_j) {
            cout << "Mike" << endl;
        } else {
            if (id_m < id_j)
                cout << "Joe" << endl;
            else
                cout << "Mike" << endl;
        }
    }

    /* 
    if there's one pile the player wins
    if there's two pile, you cannot remove all the pile so that the other player will win
            so if there's 1 1 you'll lose, if it's 1 2, you always remove the 2nd one, and so on
            if there's 1 3 you want to make it 1 1 so the other player has to remove a pile, so you could win
            
            if there's 3 3 and you go first, if you remove it to 1 pile you'll lose
                if you remove it to 3 1 you'll lose too, because it will be 1 1 at next turn
                if you remove it to 3 2, the other can choose to remove it to 
                     [1, 2] -> [1, 1] ->y ou win
                    [2, 2] -> [1, 2]
                      [3. 1] -> [2, 1]
        if there's two piles 
        even if two players play optimally the winner is determined
        a player can remove however much stones
     */
}