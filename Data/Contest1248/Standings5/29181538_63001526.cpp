#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define qaq std::ios::sync_with_stdio(false);
#define qwq cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
inline void fast(){qaq qwq;}
ll dp[N];
int n,m;
int main()
{
	fast();
	cin>>n>>m;
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=1e5;i++)dp[i]=dp[i-1]+dp[i-2],dp[i]%=mod;
	cout<<((dp[n]-1)*2%mod+(dp[m]-1)*2%mod+2)%mod<<endl;
	return 0;
}