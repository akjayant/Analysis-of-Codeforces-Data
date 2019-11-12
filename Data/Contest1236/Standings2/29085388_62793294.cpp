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

int main()
{
	ll n ;
	cin >> n ;
	ll arr[n][n] ;
	ll cnt = 1 ;
	for(ll i = 0 ; i < n ; i += 2)
	{
		for(ll j = 0 ; j < n ; j++)
			arr[i][j] = cnt , cnt++ ;
		if((i + 1) < n)
		{
			for(ll j = n-1 ; j >= 0 ; j--)
				arr[i+1][j] = cnt , cnt++ ;
		}
	}
	fo(j , n)
	{
		fo(i , n)
			cout << arr[i][j] << ' ';
		cout << '\n' ;	
	}
	return 0 ;
}