#include <bits/stdc++.h>
#define fs first
#define sc second
#define mx 105
#define mod 1000000007
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define all(a) a.begin(),a.end()
using namespace std;
int dp[mx][mx][mx];
int rec(int a, int b, int c){
	int &ret = dp[a][b][c];
	if(ret != -1) return ret;
	ret = 0;
	if(a>=1 && b>=2) ret = rec(a-1, b-2, c) + 3;
	if(b>=1 && c>=2) ret = max(ret, rec(a, b-1, c-2) + 3);
	return ret;
}
int main()
{
	memset(dp, -1, sizeof dp);
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", rec(a, b, c));
	}
	return 0;
}