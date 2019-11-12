#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define u_mu unordered_multiset
#define u_s unordered_set
using namespace std;
long long d,z,mn = 1000000001,mx,sum,k,pos,l,x,y,r,n,m,ans,a1,a2,a3;
int a[200002],b[200002];
bool ok[200002],ko;
main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cin >> l;
	while(l){
		--l;
		cin >> n;
		for(int i = 1;i <= n;++i){
			cin >> a[i];
		}
		sort(a+1,a +1+ n);
		reverse(a+1,a +1+ n);
		for(int i = 1;i <= n;++i){
			if(a[i] >= i){
				sum = i;
			}
			else
				break;
		}
		cout << sum <<"\n";
	}
}