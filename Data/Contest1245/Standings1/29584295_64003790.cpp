#include<bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define orta ((bas+son)/2)
#define st first
#define nd second
#define ll long long
#define N 100005
#define inf 1000000000000000
#define MOD 16769023
using namespace std;

void solve() {

	int a,b;

	scanf("%d %d",&a,&b);

	if(__gcd(a,b)==1) printf("finite\n");
	else printf("Infinite\n");

}

int main() {

	int t;

	scanf("%d",&t);

	while(t--) solve();

}