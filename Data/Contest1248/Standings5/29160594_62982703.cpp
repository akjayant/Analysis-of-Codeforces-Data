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

int main()
{
	ll test;
	scanf("%lld", &test);

	ll x, n, m, odd1, odd2, ev1, ev2, ans;

	while(test--) {
		odd1 = odd2 = ev1 = ev2 = 0;

        scanf("%lld", &n);
        for(ll i = 0; i < n; i++) {
			scanf("%lld", &x);
			if(x%2) odd1++;
			else ev1++;
        }

        scanf("%lld", &m);
        for(ll i = 0; i < m; i++) {
			scanf("%lld", &x);
			if(x%2) odd2++;
			else ev2++;
        }

        ans = (odd1*odd2) + (ev1*ev2);
        printf("%lld\n", ans);
	}
}
