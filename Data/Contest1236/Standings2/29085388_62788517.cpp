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
ll z = 1000000007 ;

ll power(ll a , ll b)
{
	if(b == 0)
		return 1 ;
	ll c = power(a , b/2) ;
	if(b % 2 == 0)
		return ((c * c)%z) ;
	else
		return ((((c*c)%z)*a)%z) ;
}

int main()
{
	ll n , m ;
	cin >> n >> m ;
	ll base = power(2 , m) ;
	base-- ;
	ll ans = power(base , n) ;
	cout << ans << endl ;
	return 0;
}