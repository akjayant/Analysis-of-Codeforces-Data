#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
int n;
void solve(){
	int a,b,c;cin >> n;
	cin >> a >> b >> c >> s;
	int ans=0;
	t=s;
	int id=0;
	for(auto cur:s){
		if(cur=='R' && b>0) b--,ans++,t[id]='P';
		else if(cur=='P' && c>0) c--,ans++,t[id]='S';
		else if(cur=='S' && a>0) a--,ans++,t[id]='R';
		else t[id]='Z';
		id++;
	}
	if(ans*2<s.size()){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(auto cur:t){
		if(cur!='Z') cout << cur;
		else if(b>0) b--,cout << "P";
		else if(c>0) c--,cout << "S";
		else if(a>0) a--,cout << "R";
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--) solve();
}