#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iomanip>
#include<cstring>
#define initdp(a,b) for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)dp[i][j]=-1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define inf 1e9+1
#define inf1 1e18+1
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l,r) l+(r-l)/2
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
void mad(ll &a,ll b){a=(a+b)%mod;if(a<0)a+=mod;}
ll gcd(ll a,ll b){ if(a>b)swap(a,b);if(!a)return b;return gcd(b%a,a);}

void solve(){
	int n;
	cin>>n;
	string s1;cin>>s1;
	int maxi=0;
	int i1=0,j1=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string s=s1;
			swap(s[i],s[j]);
			int suf[n+1],check[n+1];
			suf[n]=0;
			int mi=0;
			for(int k=n-1;k>=0;k--){
				if(s[k]=='('){
					suf[k]=suf[k+1]+1;
					mi++;
				}
				else {
					suf[k]=suf[k+1]-1;
					if(mi>=0)mi=-1;
					else mi--;
				}
				if(suf[k]>=0&&mi>=0)check[k]=1;
				else check[k]=0;
			}
			int cur=0,mini=1e9,cnt=0;
			for(int k=0;k<n-1;k++){
				if(s[k]=='(')cur++;
				else cur--;
				mini=min(mini,cur);
				if(check[k+1]&&suf[k+1]+mini>=0&&suf[k+1]+cur==0){cnt++;}//cout<<k<<" ";}
			}
			if(s[n-1]=='(')cur++;
			else cur--;
			//cout<<"\n";
			if(cur==0&&mini>=0)cnt++;
			if(cnt>maxi){
				i1=i;
				j1=j;
				maxi=cnt;
			}
			//cout<<s<<" "<<cnt<<"\n";
		}
	}
	cout<<maxi<<"\n";
	cout<<i1+1<<" "<<j1+1<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
}