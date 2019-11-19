#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;


signed main(){
	int N;
	cin>>N;
	vector<int> a(N); for(auto& e:a)cin >> e;
	sort(ALL(a));
	int x=0,y=0;
	REP(i,(N+1)/2){
		x+=a.back();
		a.pop_back();
	}
	REP(i,N/2){
		y+=a.back();
		a.pop_back();
	}
	cout<<x*x+y*y<<endl;
}