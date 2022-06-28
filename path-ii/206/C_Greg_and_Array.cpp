/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/296/problem/C
 */

#include <iostream>
#include <cstdio>
#define maxn 200000
using namespace std;
long long a[maxn],aa[maxn],ab[maxn],ba[maxn],bb[maxn],l[maxn],r[maxn],d[maxn];
long long n,m,k;
int main(){
 	cin>>n>>m>>k;
 	for(int i=1;i<=n;i++) cin>>a[i];
 	for(int i=1;i<=m;i++) cin>>l[i]>>r[i]>>d[i];
 	while(k--) {
 		int x,y;
 		cin>>x>>y;
 		aa[x]++;
 		ab[y]++;
 	}
 	long long   open=0;
 	for(int i=1;i<=m;i++) {
 	 	open+=aa[i]-ab[i-1];
 	 	ba[l[i]]+=d[i]*open;
 	 	bb[r[i]]+=d[i]*open;
 	}
 	open=0;
 	for(int i=1;i<=n;i++) {
 		open+=ba[i]-bb[i-1];
 		cout<<a[i]+open<<" ";
 	}
 	return 0;
}