#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int > pp;

 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=5e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;


void solve(){
	int n;
	string s;
	cin>>n>>s;
	vector<int > at;
	for (int i = 0; i < n; ++i){
		if(s[i]=='1')at.push_back(i);
	}
	if(sz(at)==0)cout<<n<<'\n';
	else if(sz(at)==1)cout<<max(max(at[0]+1,n-at[0])*2,n)<<'\n';
	else{
		int cn1 = at[0],cn2 = at.back();
		int an = max(n-cn1,cn2+1)*2;
		an=max(an,cn1+1+cn2-cn1+1+cn2-cn1);
		an=max(an,n-cn2+cn2-cn1+1+cn2-cn1);
		an=max(an,n);
		cout<<an<<'\n';
	}
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;

	while(t--)solve();
	
	return 0;
}

