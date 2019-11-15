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
		int N, a, b, c, d=0;
		string A, B;
		cin>>N>>a>>b>>c>>A;
		for(char x:A) {
			if(x=='R' && b) B+='P', b--, d++;
			else if(x=='P' && c) B+='S', c--, d++;
			else if(x=='S' && a) B+='R', a--, d++;
			else B+='.';
		}
		for(char&x:B) if(x=='.') {
			if(a) a--, x='R';
			else if(b) b--, x='P';
			else if(c) c--, x='S';
		}
		if((N+1)/2<=d) {
			cout<<"YES\n"<<B<<'\n';
		} else {
			cout<<"NO\n";
		}
	}
}