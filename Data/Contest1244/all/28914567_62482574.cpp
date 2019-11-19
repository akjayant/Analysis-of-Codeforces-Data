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

ll updatel(ll l_ind , ll arr[] ,ll r_ind)
{
	for(ll i = l_ind + 1 ; i <= r_ind ; i++)
	{
		if(arr[i] == arr[l_ind])
			l_ind = i ;
		else
			break ;
	}
	return l_ind ;
}

ll updater(ll r_ind , ll arr[] ,ll l_ind)
{
	for(ll i = r_ind - 1 ; i >= l_ind ; i--)
	{
		if(arr[i] == arr[r_ind])
			r_ind = i ;
		else
			break ;
	}
	return r_ind ;
}

int main()
{
	ll n , k ;
	cin >> n >> k ;
	ll arr[n] ;
	fo(i , n)
	{
		cin >> arr[i] ;
	}
	sort(arr , arr + n) ;
	ll l_ind = 0 , r_ind = (n - 1) ;
	ll l , r ;
	l_ind = updatel(l_ind , arr , r_ind) ;
	r_ind = updater(r_ind , arr , l_ind) ;
	while(l_ind != r_ind && k >= 0)
	{
	    //cout << "l_ind = " << l_ind << "  r_ind = " << r_ind ;
		l = l_ind + 1 ;
		r = n - r_ind ;
		//cout << "  l = " << l << "   r = " << r << endl ;
		if(l <= r)
		{
			ll diff = arr[l_ind + 1] - arr[l_ind] ;
			ll change = min(diff , k/l) ;
			arr[l_ind] += change ;
			k -= (change * l) ;
			//cout << "diff = " << diff << "  change = " << change << endl ;
			if(change == diff)
				l_ind = updatel(l_ind , arr , r_ind) ;
			else
				break ;
		}
		else
		{
			ll diff = arr[r_ind] - arr[r_ind - 1] ;
			ll change = min(diff , k/r) ;
			arr[r_ind] -= change ;
			k -= (change * r) ;
			//cout << "diff = " << diff << "  change = " << change << endl ;
			if(change == diff)
				r_ind = updater(r_ind , arr , l_ind) ;
			else
				break ;
		}
	}
	cout << arr[r_ind] - arr[l_ind] << endl ;
	return 0;
}
