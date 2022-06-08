// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

#define MAXN 100001

int spf[MAXN];

void sieve() {
	spf[1] = 1;
	for (int i=2; i<MAXN; i++)
        spf[i] = i;
	for (int i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (int i=3; i*i<MAXN; i++) {
		if (spf[i] == i) {
			for (int j=i*i; j<MAXN; j+=i)
				if (spf[j]==j) spf[j] = i;
		}
	}
}

vector<int> getFactorization(int x) {
	vector<int> ret;
	while (x != 1) {
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	// precalculating Smallest Prime Factor
	sieve();
	int x = 12246;
	cout << "prime factorization for " << x << " : ";

	// calling getFactorization function
	vector <int> p = getFactorization(x);

	for (int i=0; i<p.size(); i++)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}
