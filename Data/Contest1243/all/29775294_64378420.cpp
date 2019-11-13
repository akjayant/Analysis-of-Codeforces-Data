#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k;cin >> k;
	while(k--){
		int n;cin >> n;
		string s,t;cin >> s >> t;
		int cnt = 0;
		vector<int> a;
		rep(i,n){
			if(s.at(i) != t.at(i)){
				cnt++;
				a.pb(i);
			}
		}
		if(cnt == 0){
			cout << "Yes" << endl;
		}
		else if(cnt == 2){
			if(s.at(a.at(0)) == s.at(a.at(1)) && t.at(a.at(0)) == t.at(a.at(1))){
				cout << "Yes" << endl;
			}
			else cout << "No" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
}