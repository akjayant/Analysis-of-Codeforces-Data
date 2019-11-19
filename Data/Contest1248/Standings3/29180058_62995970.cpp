#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int fb[1000000];
int main(void){
int n,m;
scanf("%d%d",&n,&m);
fb[0]=fb[1]=2;
for(int i=2;i<=100000;i++)fb[i]=(fb[i-1]+fb[i-2])%mod;
int ans=2;
for(int i=2;i<=n;i++)ans=(ans+fb[i-2])%mod;
for(int i=2;i<=m;i++)ans=(ans+fb[i-2])%mod;
cout<<ans<<endl;
}