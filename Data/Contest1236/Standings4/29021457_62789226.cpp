#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll ksm(ll a,ll b){
ll ret=1,tem=a;
while(b){
if(b&1)ret=ret*tem%mod;
tem=tem*tem%mod;
b>>=1;
}
return ret;
}
int n,m;
int main(void){
cin>>n>>m;
m=(ksm(2,m)-1+mod)%mod;
n=ksm(m,n);
cout<<n;
}