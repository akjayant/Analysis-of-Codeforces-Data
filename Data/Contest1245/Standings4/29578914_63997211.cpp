#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const double eps=1e-12;


double cross(pair<double,double>O,pair<double,double>A,pair<double,double>B){
    return (A.fr-O.fr)*(B.sc-O.sc)-(A.sc-O.sc)*(B.fr-O.fr);
    //pozitiv stanga
    //negativ dreapta
}

int t,a,b;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(__gcd(a,b)==1){
            cout << "Finite" << '\n';
        }
        else cout << "Infinite" << '\n';
    }


}

