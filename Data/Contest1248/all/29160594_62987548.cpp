#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
#define filein freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", stdout)
#define inf 1000000009
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pll pair<ll, ll>

#define MX 100005
ll arr[MX];

int main()
{
	ll n;
	scanf("%lld", &n);

	ll sm = 0;
	for(ll i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		sm += arr[i];
	}

	sort(arr, arr+n, greater<int>());

	ll x = 0, y = 0;
	n = (n+1)/2;
	for(ll i = 0; i < n; i++) {
        x += arr[i];
	}

	y = sm - x;

    printf("%lld\n", x*x+y*y);
}
