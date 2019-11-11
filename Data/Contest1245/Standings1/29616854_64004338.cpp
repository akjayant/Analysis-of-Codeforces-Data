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
int t;
int n,a,b,c;
char s[105];
char ans[105];
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>c;
		cin>>s+1;
		int cnt=0;
		for (int i=1;i<=n;++i){
			if (s[i]=='R'){
				if (b){
					--b;++cnt;ans[i]='P';
				}
				else ans[i]='?';
			}
			if (s[i]=='P'){
				if (c){
					--c;++cnt;ans[i]='S';
				}
				else ans[i]='?';
			}
			if (s[i]=='S'){
				if (a){
					--a;++cnt;ans[i]='R';
				}
				else ans[i]='?';
			}
		}
		if (cnt*2>=n){
			cout<<"YES\n";
			REP(i,n){
				if (ans[i]=='?'){
					if (a) --a,ans[i]='R';
					else if (b) --b,ans[i]='P';
					else if (c) --c,ans[i]='S';
				}
				cout<<ans[i];
			}
			cout<<endl;
		}
		else cout<<"NO\n";
	}
	return 0; 
}