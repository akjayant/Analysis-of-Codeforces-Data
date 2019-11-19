#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	long long int max1=max(n,m);
	long long int dp[max1+1];
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=max1;i++){
		dp[i]=dp[i-1]%mod+dp[i-2]%mod;
	}
	long long int ans=(((dp[m]+dp[n]-1)%mod+mod)*2)%mod;
	cout<<ans;
}