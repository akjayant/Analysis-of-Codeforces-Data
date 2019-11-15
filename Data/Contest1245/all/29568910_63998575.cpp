#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define lop(i,s,e) for(int i=s;i<=e;i++)
#define sort(v) sort(v.begin(),v.end())
#define prina(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl; 
#define prin2da(a,n,m) lop(i,0,n-1){lop(j,0,m-1)cout<<a[i][j]<<" ";cout<<endl;} 
using namespace std;

int main()
{
IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin>>t;
    while(t--)
    {
    	ll x,y;
    	cin>>x>>y;
    	if(__gcd(x,y)==1)
    		cout<<"Finite\n";
    	else
    		cout<<"Infinite\n";
    }
}