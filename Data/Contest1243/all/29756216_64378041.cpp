#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define mp make_pair
#define int long long
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
///#define cin fin
///#define cout fout
using namespace std;

const int mod=1e9+7;

int q,n;
string s,t;

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    cin >> q;
    while(q--){
        cin >> n >> s >> t;
        int j=-1,cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i] && j==-1) j=i;
            else if(s[i]!=t[i] && j>=0){
                swap(s[i],t[j]);
            }
        }
        if(j>=0 && s!=t) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
}
