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

int n;
char s[N];

void solve() {

	scanf("%d",&n);

	scanf("%s",s+1);

	int ans=n;

	for(int i=1;i<=n;i++) {

		if(s[i]=='1') {

			ans=max(ans,max(i,n-i+1)*2);

		}

	}

	printf("%d\n",ans);

}

int main() {

	int t;

	scanf("%d",&t);

	while(t--) solve();

}