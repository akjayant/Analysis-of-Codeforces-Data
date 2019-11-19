//#include<bits/stdc++.h>
#define ll long long
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<utility>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ;
ll mod = 998244353 ;

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		string str ;
		int n ;
		cin >> n >> str ;
		vector<ll> v ;
		fo(i , n)
		{
			if(str[i] == '1')
				v.pub(i) ;
		}
		int ans = 0 ;
		if(v.size() != 0)
		{
			int max_1 = max((v[0] + 1) , (n - v[0])) ;
			int max_2 = max((v[v.size() - 1] + 1 ), (n - v[v.size() - 1])) ;
			max_1 = max(max_1 , max_2) ;
			ans = 2*(max_1) ;
		}
		else
		{
			ans = n ;
		}
		cout << ans << '\n' ;
	}
	return 0;
}