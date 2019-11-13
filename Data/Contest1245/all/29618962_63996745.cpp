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
		ll a, b ;
		cin >> a >> b ;
		ll c = gcd(a , b) ;
		if(c == 1)
			cout << "Finite" << '\n';
		else
			cout << "Infinite" << '\n' ;
	}
	return 0;
}
