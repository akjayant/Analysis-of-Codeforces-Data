#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define sz(x) ((int)x.size())
#define ii pair<int,int>
#define ll long long
#define ppb pop_back
#define N 200005
#define MOD 1000000007
#define inf 2000000000
#define iii pair<pair<int,int>,int>
#define P 1000003
using namespace std;

void solve() {

	int a,b,c,d,k;

	scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);

	for(int i=0;i<=100;i++) {

		for(int j=0;j<=100;j++) {

			if(i*c>=a && j*d>=b && i+j<=k) {

				printf("%d %d\n",i,j);

				return ;

			}

		}

	}

	printf("-1\n");

}

int main() {

	int t;

	scanf("%d",&t);

	while(t--) solve();

}