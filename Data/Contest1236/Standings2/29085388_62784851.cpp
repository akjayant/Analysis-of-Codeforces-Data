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


int main()
{
	ll t ;
	cin >> t ;
	while(t--)
	{
		ll a,b , c, x , y ;
		cin >> a >> b >> c ;
		x = min(b , c/2) ;
		b -= x ;
		y = min(a , b/2) ;
		cout << 3*(x+y) << '\n' ;
	}
	return 0;
}