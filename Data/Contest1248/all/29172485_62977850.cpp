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
	int Q;
	cin>>Q;
	vector<int>ans;
	while(Q--){
		int N;
		cin>>N;
		vector<int>a(N);
		REP(i,N)cin>>a[i];
		int M;
		cin>>M;
		vector<int>b(M);
		REP(i,M)cin>>b[i];
		int aodd=0,aeven=0,bodd=0,beven=0;
		REP(i,N){
			if(a[i]%2)aodd++;
			else aeven++;
		}
		REP(i,M){
			if(b[i]%2)bodd++;
			else beven++;
		}
		ans.push_back(aodd*bodd+aeven*beven);
	}
	for(auto &e:ans)cout << e << endl;
}