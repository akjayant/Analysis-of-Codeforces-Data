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
		int a , b , c , d , k ;
		cin >> a >> b >> c >> d >> k ;
		int x , y ;
		x = (a+c - 1)/c ;
		y = (b+ d-1)/d ;
		if(x + y > k)
			cout << -1 << '\n' ;
		else
			cout << x << ' ' << y << '\n';
	}
	return 0;
}