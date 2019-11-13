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
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std ;
ll z = 998244353 ;

ll gcd(ll a,ll b)
{
	if(a < b)
		return gcd(b , a) ;
	if(b == 0)
		return a ;
	return gcd(b , a%b) ;
}


int main()
{
	ll t ;
	cin >> t ;
	while(t--)
	{
		ll n , a , b , c;
		cin >> n >> a >> b >> c ;
		string s ;
		cin >> s ;
		ll cnt_r = 0, cnt_s = 0, cnt_p = 0 ;
		fo(i , s.size())
		{
			if(s[i] == 'R')
				cnt_r++ ;
			if(s[i] == 'S')
				cnt_s++ ;
			if(s[i] == 'P')
				cnt_p++ ;
		}
		ll req = n/2 ;
		if(n%2 == 1)
			req++ ;
		ll ans = min(a , cnt_s) + min(b , cnt_r) + min(c , cnt_p) ;
		//cout << ans << ' ' << cnt_p << ' ' << cnt_s << ' ' << cnt_r << endl ;
		if(ans < req)
			cout << "NO" << '\n' ;
		else
		{
			ll arr[n] ;
			fo(i , n)
			{
				if(s[i] == 'R')
				{
					if(b > 0)
					{
						arr[i] = 'P' ;
						b -- ;
					}
					else
						arr[i] = 0 ;
				}
				if(s[i] == 'P')
				{
					if(c > 0)
					{
						arr[i] = 'S' ;
						c -- ;
					}
					else
						arr[i] = 0 ;
				}
				if(s[i] == 'S')
				{
					if(a > 0)
					{
						arr[i] = 'R' ;
						a -- ;
					}
					else
						arr[i] = 0 ;
				}
			}
			fo(i , n)
			{
				if(arr[i] == 0)
				{
					if(a > 0)
					{
						arr[i] = 'R' ;
						a-- ;
						continue ;
					}
					if(c > 0)
					{
						arr[i] = 'S' ;
						c-- ;
						continue ;
					}
					if(b > 0)
					{
						arr[i] = 'P' ;
						b-- ;
						continue ;
					}
				}
			}
			cout << "YES" << '\n';
			fo(i,n)
				cout << (char)arr[i] ;
			cout << '\n' ;

		}
	}
	return 0;
}
