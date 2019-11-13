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
		int N;
		cin>>N;
		string a, b;
		cin>>a>>b;
		int j=-1;
		rep(i, 0, N) if(a[i]!=b[i]) {
			if(j<0) j=i;
			else {
				swap(a[i], b[j]);
				break;
			}
		}
		cout<<(a==b?"Yes":"No")<<'\n';
	}
}