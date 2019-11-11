#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define REP(i,n) for (int i=1;i<=n;++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define read(x) scanf("%d",&x)
int n;
char s[100005];
ll dp[100005];
const ll MOD=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	cin>>s+1;
	n=strlen(s+1);
	dp[0]=dp[1]=1;
	bool bad=0;
	if (s[1]=='m'||s[1]=='w') bad=1;
	for (int i=2;i<=n;++i){
		if (s[i]=='m'||s[i]=='w') bad=1;
		if (s[i]!='n'&&s[i]!='u') dp[i]=dp[i-1];
		else{
			if (s[i]==s[i-1]) dp[i]=(dp[i-1]+dp[i-2])%MOD;
			else dp[i]=dp[i-1];
		}
	}
	if (bad) cout<<0<<endl;
	else cout<<dp[n]<<endl;
	return 0;
}