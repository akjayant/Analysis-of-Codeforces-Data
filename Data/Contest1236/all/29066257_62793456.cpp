/*
  user: sky48
  language: c++
  for dream for young
*/
#include<iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
ll n,m,ans;
ll gets()
{
	ll v=0; char ch;bool f=0;
	while(!isdigit(ch=getchar())) if(ch=='-') f=1; v=ch-48;
	while( isdigit(ch=getchar())) v=(v<<1)+(v<<3)+ch-48;
	return f?-v:v;
}
ll fast(ll x,ll k){
	ll tmp=1;
	while(k){
		if(k&1) tmp=tmp*x%mod;
		x=x*x%mod, k>>=1; 
	}
	return tmp;
}
int main ()
{
//  freopen("tt.txt","r",stdin);
	n=gets(), m=gets();
	ans=fast(2,m)-1;
	ans=fast(ans,n); 
	cout<<ans<<endl; 
	return 0;
}
