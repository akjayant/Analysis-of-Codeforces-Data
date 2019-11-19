/*input
2 3
*/
#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define MAX 100005
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define ff first
#define ss second
#define T int t;cin>>t;while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define umi unordered_map<int,int>
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int> >
#define inp(n) for(int i=0;i<n;i++)
#define N 2000005

using namespace std;
using namespace std::chrono;

int ways(int n){
	if(n==1)	return 2;
	int dp[n+1][4]={};
	dp[0][0] = 1,dp[0][1] = 1;
	dp[0][2] = 1,dp[0][3] = 1;
	for(int i=1;i<n-1;i++){
		dp[i][0] = dp[i-1][2];
		dp[i][1] = (dp[i-1][0]+dp[i-1][2])%MOD;
		dp[i][2] = (dp[i-1][1]+dp[i-1][3])%MOD;
		dp[i][3] = dp[i-1][1];
	}
	return (dp[n-2][0]+dp[n-2][1]+dp[n-2][2]+dp[n-2][3])%MOD;
}

int solve(int n,int m){
	int w1 = ways(n);
	int w2 = ways(m);
	return (w1+w2+MOD-2)%MOD;
}

signed main(){
	int n,m;
	cin >> n >> m;
	cout << solve(n,m);
}
