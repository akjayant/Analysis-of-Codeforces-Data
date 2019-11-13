/****************************
* Author : 水娃             *
* Date : 2019-11-01-22.31.01*
****************************/
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a))
#define ll long long
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
const int MAXN=(int)1e5+10;
const int mo=(int)1e9+7;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(gcd(a,b)==1)cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
    return 0;
}
