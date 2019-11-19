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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int N;
	cin>>N;
	vector<vector<int>> A(3, vector<int>(N, -1));
	vector<vector<int>> G(N);
	rep(i, 0, 3) rep(j, 0, N) cin>>A[i][j];
	rep(i, 1, N) {
		int x, y;
		cin>>x>>y; --x, --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int first=0;
	rep(i, 0, N) {
		if(G[i].size()>2) X(-1)
		else if(G[i].size()==1) first=i;
	}

	vector<int> B(N); B[0]=first;
	rep(i, 1, N) {
		int p=B[i-1];
		if(i==1 || G[p][0]!=B[i-2]) B[i]=G[p][0];
		else B[i]=G[p][1];
	}

	vector<int> C{0, 1, 2}, D(N);
	ll m=INFL;
	do {
		ll x=0;
		rep(i, 0, N) x+=A[C[i%3]][B[i]];
		if(x<m) {
			m=x;
			rep(i, 0, N) D[B[i]]=C[i%3];
		}
	} while(next_permutation(begin(C), end(C)));

	if(m==INFL) X(-1)
	cout<<m<<'\n';
	for(int i:D) cout<<C[i]+1<<' ';
}