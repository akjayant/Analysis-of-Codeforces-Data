#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int n,m;
ll a[100006],b[100006];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
a[1]=2;
a[2]=4;
a[3]=6;
for(int i=4;i<=n;i++)
a[i]=(a[i-1]*2-a[i-3]+mod*10)%mod;
b[1]=a[n];
b[2]=(a[n]+2)%mod;
b[3]=(a[n]+4)%mod;
for(int i=4;i<=m;i++)
    b[i]=(b[i-1]*2-b[i-3]+mod*10)%mod;
cout<<b[m];
return 0;
}
