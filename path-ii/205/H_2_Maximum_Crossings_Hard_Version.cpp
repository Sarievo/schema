/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/1676/H2
 */

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<typename X> inline X abs(const X& a) {return (a<0?-a:a);} // std methods?
template<typename X> inline X sqr(const X& a) {return (a*a);}
using namespace std;

using ll=long long;
#define int ll
/** METHOD */
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b) // i[0-b], go to range asc
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b) // i[b-0], go to range desc
// #define foreach(it,a) for(__typeof((a).begin())it=(a).begin();it!=(a).end();it++)
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;} // if a < b, a is replaced by b
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;} // if a > b, a is replaced by b
#define SUM(a) accumulate(all(a),int(0)) //...
/** VECTOR */
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using vi=vc<int>;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){os<<"{";for(auto e:v)os<<e<<",";return os<<"}";} // ease for debugging vectors
/** PAIR   */
using pi=pair<int,int>;
#define mp make_pair
#define a first
#define b second
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"{"<<p.a<<","<<p.b<<"}";} // ease for debugging pairs

long long merge(int a[], int temp[], int left, int mid, int right) {
   int i, j, k;
   long long count = 0;
   i = left;
   j = mid;
   k = left;
   while ((i <= mid - 1) && (j <= right)) {
      if (a[i] <= a[j]){
      temp[k++] = a[i++];
      } else {
         temp[k++] = a[j++];
         count += (mid - i);
      }
   }
   while (i <= mid - 1)
      temp[k++] = a[i++];
   while (j <= right)
      temp[k++] = a[j++];
   for (i=left; i <= right; i++)
      a[i] = temp[i];
   return count;
}
long long mergeSort(int a[], int temp[], int left, int right){
   int mid;
   long long count = 0;
   if (right > left) {
      mid = (right + left)/2;
      count = mergeSort(a, temp, left, mid);
      count += mergeSort(a, temp, mid+1, right);
      count += merge(a, temp, left, mid+1, right);
   }
   return count;
}
long long aInversion(int a[], int n) {
   int temp[n];
   return mergeSort(a, temp, 0, n - 1);
}

// void f_naive() {
//     int n;
// 	cin >> n;
// 	int a[n];
// 	for (int i = 0; i < n; i++) {
// 		cin >> a[i];
// 	}
// 	int res = 0;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = i + 1; j < n; j++) {
// 			if (a[i] >= a[j]) {res++;}
// 		}
// 	}
// 	cout << res << '\n';
// }

void f() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long res = aInversion(a, n);
	sort(a, a + n);
	long long curr = 1;
	for (int i = 1; i < n; i++) {
	    if (a[i] != a[i - 1]) {res += (curr * (curr - 1)) / 2; curr = 1;}
	    else {curr++;}
	}
	res += (curr * (curr - 1)) / 2;
	cout << res << '\n';
}

signed main() {
    IOS;
    int T=1;
    cin >> T;
    while (T--) {
        f();
    }
}