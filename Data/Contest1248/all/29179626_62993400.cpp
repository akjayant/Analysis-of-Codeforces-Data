#include<stdio.h>
#include<bits/stdc++.h>
#define LL long long
#define rel(i,s,n) for(int i=s;i<n;i++)
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define red(i,s,n) for(int i=s;i>=n;i--)
#define res(i,x) for(int i=Last[x];i;i=Next[i])
using namespace std;
LL a[100005];
LL n,tmp1,tmp2,ans;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, 1, n)cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	rep(i, 1, n / 2)tmp1 += a[i];
	rep(i, n / 2 + 1, n)tmp2 += a[i];
	ans = tmp1*tmp1 + tmp2*tmp2;
	cout << ans;
}