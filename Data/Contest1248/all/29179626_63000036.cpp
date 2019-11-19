#include<stdio.h>
#include<bits/stdc++.h>
#define LL long long
#define rel(i,s,n) for(int i=s;i<n;i++)
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define red(i,s,n) for(int i=s;i>=n;i--)
#define res(i,x) for(int i=Last[x];i;i=Next[i])
using namespace std;
const LL mod = 1e9 + 7;
LL n, m;
LL f[100005];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if(n > m)swap(n, m);
	f[1] = 2;
	f[2] = 4;
	rep(i,3,m)f[i]+=(f[i-1]+f[i-2])%mod;
	cout << (f[n]+f[m]-2)%mod;
	
}