#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
const int N = int(5e5) + 12, mod = int(1e9)  + 7;
int a[N];
string s, t;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--) {
        int n;
        cin>>n;
        cin>>s>>t;
        if(s == t) {
            cout<<"Yes"<<endl;
            continue;
        }
        int ind1 = -1, ind2 = -1, cnt = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == t[i])
                continue;
            cnt++;
            if(ind1 == -1) {
                ind1 = i;
                continue;
            }
            ind2 = i;
        }
        if(cnt != 2) {
            cout<<"No"<<endl;
            continue;
        }
        if(s[ind1] == s[ind2] && t[ind2] == t[ind1]) {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
}
/*
 5 5 6
 1 2 3 4 5
 1 2 1 1
 2 3 1 3
 4 2 4 4
 2 5 1 4
 3 2 2 3
 3 2 3 3
 */
