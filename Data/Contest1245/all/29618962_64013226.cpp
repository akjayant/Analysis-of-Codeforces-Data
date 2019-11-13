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
ll z = 1000000007 ;



int main()
{
	ll arr[100001] ;
	arr[0] = 0 , arr[1] = 1 , arr[2] = 2 ;
	for(ll i = 3 ; i < 100001 ; i++)
	{
		arr[i] = (arr[i-1] + arr[i-2])%z ;
	}
	string s ;
	ll ans = 1 ;
	cin >> s ;
	int flag = 1 ;
	ll cnt = 0 ;
	char curr ;
	fo(i , s.size())
	{
		if(s[i] == 'w' || s[i] == 'm')
			ans = 0 ;
		else
		{
			if(s[i] == 'n' || s[i] == 'u')
			{
				cnt = 1 ;
				curr = s[i] ;
				i++ ;
				while(s[i] == curr)
				{
					cnt ++ ;
					i++ ;
				}
				i-- ;
				ans *= (arr[cnt]) ;
				ans %= z ;
			}
		}

	}
	cout << ans << endl ;
	return 0;
}
