#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
typedef pair<int,int > pp;
 
 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=2e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;

string s,t;
int n;
void solve(){
	cin>>n;
	cin>>s>>t;
	vector<int > df;
	for(int i=0;i<n;i++){
		if(s[i]!=t[i])df.push_back(i);
	}
	if(sz(df)==0){
		cout<<"Yes\n";
	}else if(sz(df)==1){
		cout<<"No\n";
	}else if(sz(df)==2){
		if(s[df[0]]==s[df[1]]&&t[df[0]]==t[df[1]]){
			cout<<"Yes\n";
		}else cout<<"No\n";
	}else{
		cout<<"No\n";
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)solve();
	
	return 0;
}
