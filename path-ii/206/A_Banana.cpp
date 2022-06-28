#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t, i, j;
    int a[26]={0};
    string s, p="";
    cin >> s >> n;
    for (i=0; i<s.size(); i++)
        a[s[i]-'a']=a[s[i]-'a']+1;
    for (i=1; i<=s.size(); i++) {
        k=0;
        for (j=0; j<26; j++) {
            k=k+a[j]/i;
            if (a[j]%i!=0)
                k=k+1;
        }
        if (k<=n) {
            t=i;
            break;
        }
    }
    
    if (i>s.size())
        cout << -1;
    else {
        for (i=0; i<n-k; i++)
            p=p+'a';
        for (i=0; i<26; i++) {
            k=a[i]/t;
            if (a[i]%t!=0)
                k=k+1;
            for (j=0; j<k; j++)
                p=p+(char)(i+'a');
        }
        cout << t << endl;
        cout << p;
    }

    return 0;
}
