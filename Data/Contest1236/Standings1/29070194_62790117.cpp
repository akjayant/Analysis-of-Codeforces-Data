#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,m;
ll Pow(ll a,int b)
{
  ll res=1;
  while(b)
  {
    if(b&1)res=res*a%mod;
    a=a*a%mod;b>>=1;
  }
  return res;
}
int main()
{
  scanf("%d%d",&n,&m);
  printf("%d\n",Pow((Pow(2,m)-1+mod)%mod,n));
  return 0;
}