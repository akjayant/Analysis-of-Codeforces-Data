#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
int f[100005];
int main()
{
f[1]=2,f[2]=4;
 for(int i=3;i<=100000;i++)f[i]=(f[i-1]+f[i-2])%mod;
 int n,m;
 cin>>n>>m;
 cout<<(f[n]+f[m]-2)%mod;
  
}
