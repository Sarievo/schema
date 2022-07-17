#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


void solve() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n), b(n), tmpa;
    map<ll,ll> amp, bmp, tmp;
    for(auto &i : a){
        cin >> i;
        amp[i]++;
    }
    for(auto &i : b){
        cin >> i;
        bmp[i]++;
    }
	
    int ans = 1e9;
    for(auto x : amp){
        for(auto y : bmp){
            if(x.second == y.second){
                ll x1 = x.first;
                ll y1 = y.first;
                if(x1 > y1) y1 += m;
                tmp = bmp;
                ll diff = y1 - x1;
                if(diff > ans) 
                    continue;
                int cool = 1;
                tmpa = a;
                for(auto &i : tmpa){
                    i = (i + diff) % m;
                    if(tmp[i] == 0){
                        cool = 0;
                        break;
                    }
                    tmp[i]--;
                }
                if(!cool) continue;
                ans = diff;
            }
        }
        break;
    }
    cout << ans;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}

//======== ⚠ Do't Complicate the Algorithm ⚠ ========

template <typename T>
void sort(vector<T> &a, bool desc) {
    if (desc) {
        sort(a.begin(), a.end(), [](T a, T b) {return a > b;}); // sort by anonymous comparator
    } else {
        sort(a.begin(), a.end());
    }
}

template <typename T>
void print(vector<T> &A) {
    int n = A.size();
    cout << n << endl;
    rp(i, n) cout << A[i] << " ";
    cout << endl;
}