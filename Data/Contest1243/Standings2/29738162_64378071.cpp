#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#define ll long long int
#define hell 1000000007LL
using namespace std;
ll power(ll x, ll y){ 
    if(y==0)
     return 1;
    else
    {
        ll p=power(x,y/2);
        if(y%2==0)
         return (p*p)%hell;
        else
        return (x*((p*p)%hell))%hell;
    }}
ll gcd(ll x,ll y)
{
    if(y==0)
     return x;
    else
    return gcd(y,x%y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    int q;
    cin>>q;
    while(q--)
    {
        int n,d=0;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<int>v;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i]){
             d++;
             v.push_back(i);}
        }
        if(d!=2)
            cout<<"No";
        else
        {
            if(t[v[0]]==t[v[1]]&&s[v[0]]==s[v[1]])
            cout<<"Yes";
            else
            cout<<"No";
        }
        cout<<"\n";
    }}