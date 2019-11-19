/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,a[100010],b=0,c=0;

int main()
{
	cin>>n;
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	rep(i,n/2) b+=a[i];
	for(int i=n/2;i<n;i++) c+=a[i];
	cout<<b*b+c*c<<endl;
	return 0;
}