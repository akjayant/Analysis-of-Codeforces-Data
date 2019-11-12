#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

void solve1(){
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	string ss,tt;
	rep(i,n){
		if(s[i]!=t[i]){
			ss+=s[i];
			tt+=t[i];
		}
	}
	if(ss.length()!=2)cout<<"No"<<endl;
	else if(!(ss[0]==ss[1]&&tt[0]==tt[1]))cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}

int main()
{
	int k;
	cin>>k;
	while(k--){
		solve1();
	}
	return 0;
}