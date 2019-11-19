#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define u_mu unordered_multiset
#define u_s unordered_set
using namespace std;
long long d,z,mn = 1000000001,mx,sum,k,pos,l,x,y,r,n,m,ans,a1,a2,a3;
int a[200002],b[200002];
set<int>st;
vector<int>v;
main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cin >> n;
	l = n;
	for(int i = 2;i <= sqrt(l);++i){
		if(l % i == 0){
			if(k == 1){
				cout << 1;
				return 0;
			}
			else{
				while(l % i == 0){
					l /= i;
					mx = i;
				}
				++k;
			}
		}
	}
	if(k == 1 && l != 1){
		cout << 1;
		return 0;
	}
	if(mx != 0){
		cout << mx;
	}
	else
		cout << n;
}