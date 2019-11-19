#include<bits/stdc++.h>
#define mod 1000000007;
#define ll long long
#define endl "\n"
#define vi vector <int>
#define vl vector <long long>
#define pb push_back
#define mk make_pair
#define pi pair <int,int>
#define pl pair <ll,ll>
#define rep(i,a,n) for(int i=a;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define rep_(i,a,n) for(int i=(n-1);i>=a;i--)
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll dp[100001]={0};
    dp[1]=1;
    dp[2]=2;
    int n,m;
    cin>>n>>m;
    for(int i=3;i<=max(m,n);i++)
    	dp[i]=(dp[i-1]+dp[i-2])%mod;
    ll ans=dp[n];
    ans=(ans+dp[m]-1)%mod;
    ans=(ans*2)%mod;
    cout<<ans<<endl;
}
