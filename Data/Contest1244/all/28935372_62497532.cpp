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
	int N; ll k;
	cin>>N>>k;
	vector<ll> A(N);
	rep(i, 0, N) cin>>A[i];
	sort(begin(A), end(A));
	int l=0, r=N-1;
	while(true) {
		while(l<r && A[l]==A[l+1]) l++;
		while(l<r && A[r]==A[r-1]) r--;
		if(l>=r || k<min(l+1, N-r)) break;
		if(l+1<=N-r) {
			ll t=min(A[l+1]-A[l], k/(l+1));
			A[l]+=t, k-=t*(l+1);
		} else {
			ll t=min(A[r]-A[r-1], k/(N-r));
			A[r]-=t, k-=t*(N-r);
		}
	}
	cout<<A[r]-A[l];
}