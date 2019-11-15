#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll arr[n];
		ll i,j;
		for(i=0;i<n;i++){
			cin >> arr[i];
		}
		sort(arr,arr+n);
		ll mx=0;
		ll count=0;
		ll best=0;
		for(i=n-1;i>=0;i--){
			count++;
			best=max(best,min(count,arr[i]));
		}
		cout << best << endl;
	}
}