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
const int mod1=998244353;

int t,cnt1,cnt2,cnt3,cnt4,n,m,x;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> x;
            if(x%2==1) cnt1++;
            else cnt2++;
        }
        cin >> m;
        for(int i=1;i<=m;i++){
            cin >> x;
            if(x%2==1) cnt3++;
            else cnt4++;
        }
        cout << (cnt1*cnt3+cnt2*cnt4) << '\n';
    }


}