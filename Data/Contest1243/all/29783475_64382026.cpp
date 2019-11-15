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
	int T;
	cin>>T;
	while(T--) {
		int N, k=0, m=0;
		cin>>N;
		vector<int> A(N+1);
		rep(i, 0, N) {
			int x;
			cin>>x;
			A[x]++;
		}
		repr(i, N+1, 1) if((k+=A[i]), k>=i) {
			m=i;
			break;
		}
		cout<<m<<'\n';
	}
}