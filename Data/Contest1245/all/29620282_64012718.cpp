#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
const int mod=1e9+7;
char s[100005];

int dp[100005][2];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	dp[1][0]=1;
	if(s[1]=='m'||s[1]=='w')
	{
		printf("0");
		return 0;
	}
	for(int i=2;i<=len;i++)
	{
		if(s[i]=='m'||s[i]=='w')
		{
			printf("0");
			return 0;
		}
		if((s[i]=='u'&&s[i-1]=='u')||(s[i]=='n'&&s[i-1]=='n'))
		{
			dp[i][1]=dp[i-1][0];
			dp[i][1]%=mod;
		}
		dp[i][0]=dp[i-1][1]+dp[i-1][0];
		dp[i][0]%=mod;
	}
	printf("%d",(dp[len][0]+dp[len][1])%mod);
}
