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
const double eps=1e-12;


double cross(pair<double,double>O,pair<double,double>A,pair<double,double>B){
    return (A.fr-O.fr)*(B.sc-O.sc)-(A.sc-O.sc)*(B.fr-O.fr);
    //pozitiv stanga
    //negativ dreapta
}

int ans=1,fib[100005];
string s;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='w') rc("0");
        else if(s[i]=='m') rc("0");
    }
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=s.size();i++){
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='n'){
            int cnt=0;
            while(s[i]=='n'){
                i++;
                cnt++;
            }
            ans*=fib[cnt];
            ans=ans%mod;
            i--;
        }
        else if(s[i]=='u'){
            int cnt=0;
            while(s[i]=='u'){
                i++;
                cnt++;
            }
            ans*=fib[cnt];
            ans=ans%mod;
            i--;
        }
    }
    rc(ans);
}

