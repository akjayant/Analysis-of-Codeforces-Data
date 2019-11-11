/****************************
* Author : 水娃             *
* Date : 2019-11-01-22.51.14*
****************************/
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a))
#define ll long long
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
const ll MAXN=(ll)1e5+10;
const ll mo=(ll)1e9+7;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
using namespace std;
ll a[110000];
vector<int>v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string x;
    cin>>x;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='m'||x[i]=='w')
        {
            cout<<"0\n";
            return 0;
        }
    }
    a[0]=1,a[1]=1;
    for(int i=2;i<=100000;i++)a[i]=(a[i-1]+a[i-2])%mo;
    int f=0,tmp=0;
    for(int i=0;i<x.length();i++)
    {
        if(f&&x[i]=='u')
        {
            tmp++;
        }
        else if(x[i]=='u')
        {
            f=1;
            tmp=1;
        }
        else if(f)
        {
            v.push_back(tmp);
            f=0;
            tmp=0;
        }
    }
    if(tmp)v.push_back(tmp);
    f=0,tmp=0;
    for(int i=0;i<x.length();i++)
    {
        if(f&&x[i]=='n')
        {
            tmp++;
        }
        else if(x[i]=='n')
        {
            f=1;
            tmp=1;
        }
        else if(f)
        {
            v.push_back(tmp);
            f=0;
            tmp=0;
        }
    }
    if(tmp)v.push_back(tmp);
    ll ans=1;
    for(int i=0;i<v.size();i++)
    {
        ans=(ans*a[v[i]])%mo;
    }
    cout<<ans<<"\n";
    return 0;
}
