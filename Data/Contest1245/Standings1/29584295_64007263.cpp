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

char ans[N],s[N];

void solve() {

	int n,a,b,c;

	scanf("%d %d %d %d",&n,&a,&b,&c);

	scanf("%s",s+1);

	int cnt=0;

	for(int i=1;i<=n;i++) {

		ans[i]='K';

		if(s[i]=='R') {

			if(b) {

				--b;
				cnt++;

				ans[i]='P';

			}

		}
		else if(s[i]=='P') {

			if(c) {

				--c;
				cnt++;

				ans[i]='S';

			}

		}
		else {

			if(a) {

				--a;
				cnt++;

				ans[i]='R';

			}

		}

	}

	if(cnt>=(n+1)/2) {
	
		printf("YES\n");
	
		for(int i=1;i<=n;i++) {

			if(ans[i]=='K') {

				if(a) {--a;ans[i]='R';}
				else if(b) {--b;ans[i]='P';}
				else {--c;ans[i]='S';}

			}

			printf("%c",ans[i]);

		}

		printf("\n");

	}
	else printf("NO\n");

}

int main() {

	int t;

	scanf("%d",&t);

	while(t--) solve();

}