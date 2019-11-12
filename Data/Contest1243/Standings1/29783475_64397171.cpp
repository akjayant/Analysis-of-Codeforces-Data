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

	auto f=[](int N, string a, string b) {
		vector<pii> A;
		rep(i, 0, N) if(a[i]!=b[i]) {
			rep(j, i+1, N) if(b[i]==b[j]) {
				swap(a[i], b[j]);
				A.push_back({i, j});
				break;
			}
			if(a[i]!=b[i]) {
				rep(j, i+1, N) if(b[i]==a[j]) {
					swap(a[j], b[j]);
					swap(a[i], b[j]);
					A.push_back({j, j});
					A.push_back({i, j});
					break;
				}
				if(a[i]!=b[i]) break;
			}
		}
		if(a!=b) return vector<pii>();
		return A;
	};

	while(T--) {
		int N;
		cin>>N;
		string a, b;
		cin>>a>>b;
		auto A=f(N, a, b);
		if(A.size()) {
			cout<<"Yes\n"<<A.size()<<'\n';
			for(auto[x,y]:A) cout<<x+1<<' '<<y+1<<'\n';
		} else {
			cout<<"No\n";
		}
	}
}