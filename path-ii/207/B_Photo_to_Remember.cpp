/** 
 * Sarievo.
 * URL: https://codeforces.com/problemset/problem/522/B
 */

#include <iostream>
#include <math.h>
#include <vector>
 
using namespace std;
 
int main(){
	int n, sum=0, h1=0 , h2=0;
	cin>>n;
	vector <int> w(n), h(n);
	for(int i=0; i<n; i++){
		cin>>w[i]>>h[i];
		sum+=w[i];
		if(h[i]>h1){
			h2 = h1;
			h1 = h[i];
		}
		else if(h[i]>h2){
			h2 = h[i];
		}
	}
	
	for(int i=0; i<n; i++){
		if(h[i] != h1) cout<<(sum-w[i])*h1<<" ";
		else cout<<(sum-w[i])*h2<<" ";
	}
	
	
	return 0;
}