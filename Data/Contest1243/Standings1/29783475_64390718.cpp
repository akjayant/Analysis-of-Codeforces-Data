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
	ll N;
	cin>>N;
	if(N==1) X(1);
	bitset<1000000> A;
	vector<int> P;
	for(int i=2; i*i<A.size(); i++) if(!A[i])
		for(int j=i*i; j<A.size(); j+=i) A[j]=true;
	for(int i=2; i<A.size(); i++) if(!A[i]) P.pb(i);
	bool f=false;
	for(int p:P) {
		if(N==p) X(N);
		ll M=N;
		f|=M%p==0;
		while(M%p==0) M/=p;
		if(M==1) X(p);
	}
	X((f?1:N));
}