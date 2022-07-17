/** 
 * Sarievo.
 * URL: https://codeforces.com/contest/1705/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

int n;

int query(string s){
    cout << s << endl;
    cout.flush();
    int x; cin >> x;
    if(x==n) exit(0);
    return x;
}

int main(){
    cin >> n;

    //query true count
    string all_T(n, 'T'), ans(n, '?');
    int cnt_T = query(all_T);
    
    //query TF
    string all_TF(n, 'T');
    for(int i=1; i<n; i+=2) all_TF[i] = 'F';
    int cnt_TF = query(all_TF);

    //begin the loop
    int l = 0, r = n-1;
    while(r >= l){
        if(r==l){ //only l is undetermined
            string s(all_T);
            s[l] = 'F';
            int k = query(s);

            if(k > cnt_T){
                ans[l] = 'F';
            }
            else{
                ans[l] = 'T';
            }
            l++; r--;
        }
        else{
            string s(all_T);
            s[l] = 'F'; s[l+1] = 'F';
            int k = query(s) - cnt_T;

            if(k == 2){
                ans[l] = 'F'; ans[l+1] = 'F';
                l += 2;
            }
            else if(k == -2){
                ans[l] = 'T'; ans[l+1] = 'T';
                l += 2;
            }
            else{
                if(r == l+1){ //only l and l+1 left; figure out the order
                    string s(all_T);
                    s[l] = 'F';
                    int k = query(s);
                    
                    if(k > cnt_T){
                        ans[l] = 'F'; ans[l+1] = 'T';
                    }
                    else{
                        ans[l] = 'T'; ans[l+1] = 'F';
                    }
                    l += 2;
                }
                else{ //determine l, l+1, r
                    string s(all_TF);
                    s[l] = 'F'; s[l+1] = 'T';

                    if(s[r] == 'F') s[r] = 'T';
                    else s[r] = 'F';

                    int k = query(s) - cnt_TF;
                    if(k == 3){
                        ans[l] = 'F'; ans[l+1] = 'T'; ans[r] = s[r];
                    }
                    else if(k == 1){
                        ans[l] = 'F'; ans[l+1] = 'T'; ans[r] = all_TF[r];
                    }
                    else if(k == -1){
                        ans[l] = 'T'; ans[l+1] = 'F'; ans[r] = s[r];
                    }
                    else{
                        ans[l] = 'T'; ans[l+1] = 'F'; ans[r] = all_TF[r];
                    }
                    l += 2; r--;
                }
            }
        }
    }
    query(ans);
}