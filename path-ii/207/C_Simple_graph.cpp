/** 
 * Sarievo.
 * URL: https://codeforces.com/group/a8Whn6p0N1/contest/387841/problem/C
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
#define DWN(i,a,b) for(int i=int(b)-1;i>=int(a);i--) // (a,b]
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
    // cin >> T;
    while (T--) f();
}
//!<---------- end of preset !<----------------------------
// void dfs(int cur_node, vvc<int>&adj, hashset<int>&visited, int&re) {
//     if (visited.count(cur_node)) {
//         re++;
//     } else {
//         visited.insert(cur_node);
//         for(auto&node:adj[cur_node]) {
//             dfs(node, adj, visited, re);
//         }
//     }
// }

// void bfs(int cur_node, vvc<int>&adjlist, )

void f() {
    int n, m; cin >> n >> m;
    vvc<int> adj(n);
    map<pi, int> retrieval;
    rep(i,m) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        a--, b--;
        retrieval[{a,b}]=i+1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set<pi> visited;
    set<int> visited_node{0}; // <-
    // set<pi> to_rmv;
    map<pi,int> to_rmv;
    deque<pi> q;
    for(auto&e:adj[0])
        q.push_back({0,e});

    while (q.size()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            pi curr = q.front(); q.pop_front();
            pi normal = curr.a < curr.b ? curr : mp(curr.b, curr.a);
            if (visited_node.count(curr.b)) {
                to_rmv[normal]++;
            } else {
                visited_node.insert(curr.b);
                // visited.insert(normal);
                for (auto&node:adj[curr.b]) {
                    q.push_back({curr.b,node});
                }
            }
        }
    }

    vi remain;
    for(auto&p:to_rmv) {
        if (p.b >= 2) p.b -= 2;
        if (p.b) {
            // cout << p.a << " " << p.b << endl;
            remain.push_back(retrieval[p.a]);
        }
    }
    sort(all(remain));
    cout << remain.size() << endl;
    cout << remain << endl;
}