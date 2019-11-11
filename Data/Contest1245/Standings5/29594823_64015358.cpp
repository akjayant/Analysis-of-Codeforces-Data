 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
 
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
int tc;
const int N=1e6+5,MOD=1e9+7;

int memo[105][105][105];
int n,a,b,c;
string s;
int win(char a , char b){
	if(b=='R')return (a=='P');
	if(b=='S')return (a=='R');
	if(b=='P')return (a=='S');
}
string ans ;
int solve(int indx,int a,int b){
	if(indx==n)return 0;

	int &ret = memo[indx][a][b];

	if(~ret)return ret;

	for(auto c : {'R','P','S'}){
		if(c == 'R'){
			if(a){
				ret = max(ret,solve(indx+1,a-1,b)+win(c,s[indx]));
			}
			else continue;
		}
		else if(c=='P'){
			if(b){
				ret = max(ret,solve(indx+1,a,b-1)+win(c,s[indx]));
			}
			else continue;
		}
		else{
			if(n-indx-a-b){
				ret = max(ret,solve(indx+1,a,b)+win(c,s[indx]));
			}
			else continue;
		}
	}

	return ret;
}
void trace(int indx,int a,int b){
	if(indx==n)return;

	
	int mx = -1;
	char who ;
	for(auto c : {'R','P','S'}){
		if(c == 'R'){
			if(a){
				if(mx<solve(indx+1,a-1,b)+win(c,s[indx]))
					who=c,mx=solve(indx+1,a-1,b)+win(c,s[indx]);
			}
			else continue;
		}
		else if(c=='P'){
			if(b){
				if(mx<solve(indx+1,a,b-1)+win(c,s[indx])){
					who=c,mx=solve(indx+1,a,b-1)+win(c,s[indx]);
				}
			}
			else continue;
		}
		else{
			if(n-indx-a-b){
				if(mx<solve(indx+1,a,b)+win(c,s[indx]))
					who=c,mx = solve(indx+1,a,b)+win(c,s[indx]);
			}
			else continue;
		}
	}
	ans.pb(who);
	if(who=='R'){
		trace(indx+1,a-1,b);
	}
	else if(who=='P'){
		trace(indx+1,a,b-1);
	}
	else{
		trace(indx+1,a,b);
	}

}
void solve(){
	ans.clear();
	cin>>n>>a>>b>>c>>s;

	for(int i=0;i<=n;i++)for(int j=0;j<=a;j++)for(int k=0;k<=b;k++)memo[i][j][k]=-1;
	if(2*solve(0,a,b)>=n){
		cout<<"YES\n";
		trace(0,a,b);

		cout<<ans<<"\n";
	}
	else{
		cout<<"NO\n";
	}
	

}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	file();

 	cin>>tc;

 	while(tc--)solve();

}