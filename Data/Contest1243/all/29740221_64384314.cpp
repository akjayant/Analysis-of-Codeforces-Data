// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
#include<unordered_map>
    
#define ll long long
    
using namespace std;

ll M = 1e9 + 7;

ll powr(ll a, ll b){
    if(b==0) return 1;
    if(a==0) return 0;
    ll ret = 1;
    while(b){
        if(b&1){
            ret *= a;
            ret %= M;
        }
        a = (a*a)%M;
        b /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    cin >> k;

    while(k--){
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        ll ctr=0, x=-1, y=-1;
        for(int i=0; i<n; i++){
            if(s[i]!=t[i]) {
                ctr++;
                if(ctr==1) x=i;
                if(ctr==2) y=i;
            }
        }

        if(ctr==0) cout << "Yes" << endl;
        else if(ctr==1 || ctr>2) cout << "No" << endl;
        else {
            if(s[x]==s[y] && t[y]==t[x]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}