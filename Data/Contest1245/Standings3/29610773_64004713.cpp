#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define X(x) { cout<<x; exit(0); }
#define rep(i,x,n) for(int i=x; i<n; i++)
#define repr(i,n,x) for(int i=n; i-->x;)
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using iii=tuple<int, int, int>;
constexpr int MOD=1e9+7;

int add(int x, int y) { return x+y-(x+y>=MOD)*MOD; }
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string S;
	cin>>S;
	for(char c:S) if(c=='w' || c=='m') X(0);
	int N=S.size();
	vector<int> D(N+1);
	D[0]=D[1]=1;
	rep(i, 2, N+1) {
		if(
			S[i-1]=='u' && S[i-2]=='u' ||
			S[i-1]=='n' && S[i-2]=='n'
		) {
			D[i]=add(D[i-1], D[i-2]);
		} else D[i]=D[i-1];
	}
	cout<<D.back();
}