#include<bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)/2)
#define st first
#define nd second
#define ll long long
#define N 600005
#define inf 1000000000
#define MOD 1000000007
#define fast_io() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(false)
using namespace std;

int n;
char s[N];
int dp[N];

int main() {

	scanf("%s",s+1);

	n=strlen(s+1);

	dp[0]=1;

	bool flag=0;

	for(int i=1;i<=n;i++) {

		dp[i]=dp[i-1];

		if(s[i]=='u' && s[i-1]=='u') dp[i]=(dp[i]+dp[i-2])%MOD;

		if(s[i]=='n' && s[i-1]=='n') dp[i]=(dp[i]+dp[i-2])%MOD;

		if(s[i]=='m' || s[i]=='w') flag=1;

	}

	if(flag) dp[n]=0;

	printf("%d",dp[n]);

}