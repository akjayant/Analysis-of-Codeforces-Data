#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("mmx,avx,fma")
//#pragma GCC optimize ("unroll-loops")
#define int long long
#define pii pair<int,int>
#define X first
#define Y second
#define ll long long
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define re return
#define pb push_back
#define PI acos(-1)
#define sz(x) ((int)(x).size())
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<double>
#define vc vector<char>
#define vii vector<pii>
#define sq(x) (x)*(x)
#define vsi vector<set<int>>
#define si set<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define double long double
#define fi first
#define se second

#define make_unique(a) sort(all(a)); a.resize(unique (all(a))-a.begin())
#define _ans(x) {cout<<(x)<<'\n'; re 0;}
#define INF (int)(1e9)
#define EPS (1e-6)
#define mod (int)(1e9+123) //1e9+123, 1e9+321, 1500000001

using namespace std;

int dj[] = { 1,0,-1,0 };
int di[] = { 0,1,0,-1 };

//int di[] = { -2,-1,1,2,2,1,-1,-2 };
//int dj[] = { 1,2,2,1,-1,-2,-2,-1 };

int fine(int i, int j, int n, int m) {
    re i >= 0 && i < n && j >= 0 && j < m;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    for(;k;k--){
        int n;
        cin>>n;
        vector<pair<char,char>>a;
        string s,t;
        cin>>s>>t;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i])a.push_back({s[i],t[i]});
        }
        if(a.size()==0)cout<<"YES\n";
        else{
            if(a.size()==2 && a[0].fi==a[1].fi &&a[0].se==a[1].se)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}